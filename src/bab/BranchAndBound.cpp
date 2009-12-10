/**
 * @file BranchAndBound.cpp
 * @date 5/12/2009
 * @author Hector <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
 * Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief 
 */

/* 
 *         File:  BranchAndBound.cpp
 *   Created on:  5/12/2009
 *       Author:  Hector
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  GenomAMf
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#define DEBUG_MODE

#ifdef DEBUG_MODE
#define TRACE(arg) (std::cout << "\nDEBUG - " << __FILE__ << ", line: " << arg << std::endl)
#define DEBUG(arg) (std::cout << "\t" << arg)
//#define DEB(arg) (std::cout << "\t" << arg)
#else
#define TRACE(arg) sizeof(std::cout << arg << std::endl)
#define DEBUG(arg) sizeof(std::cout << arg)
#endif

#include "BranchAndBound.h"

BranchAndBound::BranchAndBound()
{
  this->originProblem = 0;
  this->bestSolution = 0;
  this->problemsToSolve = QStack<Problem *> ();
  this->bound = 0;
}

BranchAndBound::BranchAndBound(Problem * originProblem, double bound)
{
  this->originProblem = originProblem;
  this->bestSolution = 0;
  this->problemsToSolve = QStack<Problem *> ();
  this->bound = bound;
}

BranchAndBound::~BranchAndBound()
{
  if (originProblem)
    delete originProblem;
  originProblem = 0;
  
  if (bestSolution)
    delete bestSolution;
  bestSolution = 0;
}

Problem * BranchAndBound::solveBb()
{
  if (originProblem->isMaximization())
    return solveBbMax();
  
  return solveBbMin();
}

Problem * BranchAndBound::solveBbMax()
{
  problemsToSolve.push(originProblem);
//  int limit = 7;
  int i = 0;
  while (!problemsToSolve.isEmpty()){//  && i < limit) {
    Problem * currentProblem = problemsToSolve.pop();
    lprec * model = currentProblem->getModel();
    int result = solve(model);
    print_solution(model, 1);
    TRACE (__LINE__ << "\n\t" << "SOL: " << currentProblem->getObjective());
    bool isFeasible = result == 0 || result == 1;
    bool isBelowBound = currentProblem->isBelowBound(bound);
    bool isIntSolution = currentProblem->isIntegerSolution();
//    bool isIntSolution = isIntegerSolution(*currentProblem);
        TRACE (__LINE__ << "\n\t" << boolalpha  
               << " isFeasible: " << isFeasible 
               << " isBelowBound: " << isBelowBound 
               << " isIntegerSolution: " << isIntSolution);

    DEBUG ( boolalpha << " Pila vacía:  "<<problemsToSolve.isEmpty());
    if (!isFeasible || isBelowBound || isIntSolution) {
      currentProblem->setFinished(true);
      TRACE (__LINE__ << "\n\t" << "Dentro del primer condicional. Problema finalizado");
      if (isIntSolution && currentProblem->isOverBound(bound)) {
        bound = currentProblem->getObjective();
        bestSolution = currentProblem;
        TRACE (__LINE__ << "\n\t" << "\t\tSolucion entera. Variables enteras.");
        DEBUG ( "bound: " << bound << endl);
      }
    }
    else {
      TRACE (__LINE__ << "\n\t" << "Else -> Ramificar");
      QList<Problem *> children = branch(*currentProblem);
      foreach (Problem * p, children)
          problemsToSolve.push(p);
      
    }
    ++i;
  }
  return bestSolution;
}

Problem * BranchAndBound::solveBbMin()
{
  problemsToSolve.push(originProblem);
  
  /*while (!problemsToSolve.isEmpty()) {
   Problem * currentProblem = problemsToSolve.pop();
   lprec * model = currentProblem->getModel();
   int result = solve(model);
   
   bool isFeasible = result == 0 || result == 1;
   bool isOverBound = currentProblem->isOverBound(bound);
   bool isIntegerSolution = currentProblem->isIntegerSolution();
   
   if (!isFeasible || isOverBound || isIntegerSolution) {
   currentProblem->setFinished(true);
   
   if (isIntegerSolution && currentProblem->isBelowBound(bound)) {
   bound = currentProblem->getObjective();
   bestSolution = currentProblem;
   }
   
   }
   else {
   QList<Problem *> children = branch(*currentProblem);
   foreach(Problem * p, children)
   problemsToSolve.push(p);
   }
   }*/
  TRACE("esto es otra prueba");
  return bestSolution;
}

QList<Problem *> BranchAndBound::branch(const Problem & problem)
{
  QList<Problem *> children;
  
  int i = 0;
  bool branched = false;
  TRACE (__LINE__ << "\n\t" << "indexesBranchingVars: ");
  for (int i = 0; i < indexesBranchingVars.count(); ++i)
    DEBUG (indexesBranchingVars.at(i) << " ");
  
  while (i < indexesBranchingVars.count() && !branched) {
    int columIndex = indexesBranchingVars.at(i);
    if (!problem.isIntegerVariable(columIndex)) {
      double lowerBound = floor(problem.getVariable(columIndex));
      double upperBound = ceil(problem.getVariable(columIndex));
      
      //      TRACE (__LINE__ << "\n\t" << "Dentro del ciclo y condicional en branch():");
      //      DEBUG ( "problem->getvariable("<< i << "): " << problem.getVariable(i) 
      //              << " lowerBound: " << lowerBound 
      //              << " upperBound: " << upperBound);

      Problem * newProblem = new Problem(problem);
      addConstraintToProblem(newProblem, columIndex, LE, lowerBound);
      children.append(newProblem);
      print_lp(newProblem->getModel());
      
      newProblem = new Problem(problem);
      addConstraintToProblem(newProblem, columIndex, GE, upperBound);
      children.append(newProblem);
      print_lp(newProblem->getModel());
      branched = true;
      newProblem = 0;
    }
    ++i;
  }
  
  return children;
}

QList<Problem *> BranchAndBound::binaryBranch(const Problem & problem)
{
  QList<Problem *> children;
  
  int i = 0;
  bool branched = false;
  
  while (i < indexesBranchingVars.count() && !branched) {
    int columnIndex = indexesBranchingVars.at(i);
    if (!problem.isIntegerVariable(columnIndex)) {
      double lowerBound = 0.0;
      double upperBound = 1.0;
      QChar prefix = problem.getColumnPrefixName(columnIndex);
        Problem * newProblem = new Problem(problem);
        addConstraintToProblem(newProblem, columnIndex, EQ, lowerBound);
        children.append(newProblem);
        
        newProblem = new Problem(problem);
        addConstraintToProblem(newProblem, columnIndex, EQ, upperBound);
        if (prefix == 'r' || prefix == 'R') {
          addMultipleConstraintsToProblem(newProblem, columnIndex, EQ, 
                                          lowerBound);
        }
        children.append(newProblem);
        branched = true;
        newProblem = 0;
      
    }
    ++i;
  }
  
  return children;
}

void BranchAndBound::addMultipleConstraintsToProblem(Problem * problem,
                                                     const int & columnIndex,
                                                     const int & constrType,
                                                     const double & bound)
{
  for (int i = 0; i < indexesBranchingVars.count(); ++i) {
    int columnIndex = indexesBranchingVars.at(i);
    QChar currentPrefix = problem->getColumnPrefixName(columnIndex);
    if (currentPrefix == 'r' || currentPrefix == 'R')
      addConstraintToProblem(problem, columnIndex, EQ, bound);
  }
}

void BranchAndBound::addConstraintToProblem(Problem * problem,
                                            const int & columnIndex,
                                            const int & constrType,
                                            const double & bound)
{
  int colno[1];
  colno[0] = columnIndex + 1;
  
  double sparserow[1];
  sparserow[0] = 1.0;
  
  problem->addConstraintex(1, sparserow, colno, constrType, bound);
}

bool BranchAndBound::isOverBound(const Problem & problem)
{
  int result = problem.compareObjectiveTo(bound);
  return result == 1;
}

bool BranchAndBound::isBelowBound(const Problem & problem)
{
  int result = problem.compareObjectiveTo(bound);
  return result == -1;
}

bool BranchAndBound::isIntegerSolution(const Problem & problem)
{
  int i = 0;
  bool isInteger = true; 
  
  while (i < indexesBranchingVars.count() && isInteger) {
    int variableIndex = indexesBranchingVars.at(i);
    isInteger = problem.isIntegerVariable(variableIndex);
  }
  
  if (isInteger)
    return true;

  return false;
}

Problem * BranchAndBound::getBestSolution()
{
  return bestSolution;
}

void BranchAndBound::setBestSolution(Problem * bestSolution)
{
  this->bestSolution = bestSolution;
}

QStack<Problem *> BranchAndBound::getProblemsToSolve()
{
  return problemsToSolve;
}

void BranchAndBound::setProblemsToSolve(QStack<Problem *> problemsToSolve)
{
  this->problemsToSolve = problemsToSolve;
}

Problem * BranchAndBound::getOriginProblem()
{
  return originProblem;
}

void BranchAndBound::setOriginProblem(Problem * originProblem)
{
  this->originProblem = originProblem;
}

double BranchAndBound::getBound()
{
  return bound;
}

void BranchAndBound::setBound(double bound)
{
  this->bound = bound;
}

QList<int> BranchAndBound::getIndexesBranchingVars()
{
  return indexesBranchingVars;
}

void BranchAndBound::setIndexesBranchingVars(QList<int> indexesBranchingVars)
{
  this->indexesBranchingVars = indexesBranchingVars;
}

