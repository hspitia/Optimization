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

//#define DEBUG_MODE

#ifdef DEBUG_MODE
#define TRACE(arg) (std::cout << "\nDEBUG - " << __FILE__ << ", line: " << arg << std::endl)
#define DEBUG(arg) (std::cout << "\t" << arg)
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
  this->indexesBranchingVars = QList<int> ();
  this->iterationsCounter = 0;
  this->relaxedIterations = 0;
  this->nodesCounter = 0;
}

BranchAndBound::BranchAndBound(Problem * originProblem, double bound)
{
  this->originProblem = originProblem;
  this->bestSolution = 0;
  this->problemsToSolve = QStack<Problem *> ();
  this->bound = bound;
  this->iterationsCounter = 0;
  this->relaxedIterations = 0;
  this->nodesCounter = 0;
  initIndexesBranchingVars();
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

void BranchAndBound::initIndexesBranchingVars()
{
  indexesBranchingVars = QList<int> ();
  
  for (int i = 0; i < originProblem->getNColumns(); ++i) {
    QChar prefix = originProblem->getColumnPrefixName(i);
    
    bool isIntegerPrefix = prefix == 'N' || prefix == 'n' || 
                           prefix == 'R' || prefix == 'r';
    
    if (isIntegerPrefix)
      indexesBranchingVars.append(i);
    
  }
}

Problem * BranchAndBound::solveBb(BranchingType branchingType)
{
  if (originProblem->isMaximization())
    return solveBbMax(branchingType);
  
  return solveBbMin(branchingType);
}

Problem * BranchAndBound::solveBbMax(BranchingType branchingType)
{
  problemsToSolve.push(originProblem);
  //  int limit = 7;
  //  int i = 0;
  iterationsCounter = 0;
  nodesCounter = 0;
  
  while (!problemsToSolve.isEmpty()) {//  && i < limit) {
    Problem * currentProblem = problemsToSolve.pop();
    lprec * model = currentProblem->getModel();
    int result = solve(model);
    
    TRACE (__LINE__ << "\n\t" << "SOL: " << currentProblem->getObjective());
    bool isFeasible = result == 0 || result == 1;
    bool isBelowBound = currentProblem->isBelowBound(bound);
    bool isIntSolution = currentProblem->isIntegerSolution();
    //    bool isIntSolution = isIntegerSolution(*currentProblem);
    TRACE (__LINE__ << "\n\t" << boolalpha
            << " isFeasible: " << isFeasible
            << " isBelowBound: " << isBelowBound
            << " isIntegerSolution: " << isIntSolution);
    
    DEBUG ( boolalpha << " Pila vac�a:  "<<problemsToSolve.isEmpty());
    if (!isFeasible || isBelowBound || isIntSolution) {
      if (iterationsCounter = 0)
        relaxedIterations = get_total_iter(model);
        
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
      QList<Problem *> children = branch(*currentProblem, branchingType);
      foreach (Problem * p, children)
        {
          problemsToSolve.push(p);
          ++nodesCounter;
          TRACE (__LINE__ << "\n\t" << "nodos: " << nodesCounter);
        }
    }
    //    ++i;
    ++iterationsCounter;
    TRACE (__LINE__ << "\n\t" << "Iteraciones: " << iterationsCounter);
  }
  return bestSolution;
}

Problem * BranchAndBound::solveBbMin(BranchingType branchingType)
{
  problemsToSolve.push(originProblem);
  int limit = 1;
//  int i = 0;
  iterationsCounter = 0;
  nodesCounter = 0;
  
  while (!problemsToSolve.isEmpty() /*&& i < limit*/) {
    Problem * currentProblem = problemsToSolve.pop();
    lprec * model = currentProblem->getModel();
    int result = solve(model);
    if (iterationsCounter == 0) {
        relaxedIterations = get_total_iter(model);
      }
    //    assert(i!=3);

    bool isFeasible = result == 0;
    bool isOverBound = currentProblem->isOverBound(bound);
    //    bool isIntSolution = currentProblem->isIntegerSolution();
    bool isIntSolution = isIntegerSolution(*currentProblem);
    
    if (!isFeasible || isOverBound || isIntSolution) {
      currentProblem->setFinished(true);
      if (isFeasible && isIntSolution && currentProblem->isBelowBound(bound)) {
        bound = currentProblem->getObjective();
        bestSolution = currentProblem;
      }
    }
    else {
      QList<Problem *> children = branch(*currentProblem, branchingType);
      foreach (Problem * p, children) {
        problemsToSolve.push(p);
        ++nodesCounter;
      }
    }
//    ++i;
    ++iterationsCounter;
//    cout << "\n\t" << "Iteraciones: " << iterationsCounter << endl;
  }
  
  return bestSolution;
}

QList<Problem *> BranchAndBound::branch(const Problem & problem,
                                        BranchingType branchingType)
{
  if (branchingType == INTEGER_BRANCHING)
    return integerBranching(problem);
  
  return binaryBranching(problem);
}

QList<Problem *> BranchAndBound::integerBranching(const Problem & problem)
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
      
      newProblem = new Problem(problem);
      addConstraintToProblem(newProblem, columIndex, GE, upperBound);
      children.append(newProblem);
      
      branched = true;
      newProblem = 0;
    }
    ++i;
  }
  
  return children;
}

QList<Problem *> BranchAndBound::binaryBranching(const Problem & problem)
{
  QList<Problem *> children;
  
  int i = 0;
  bool branched = false;
  
  TRACE (__LINE__ << "\n\t" << "binaryBranching");
  //  DEBUG ("");
  while (i < indexesBranchingVars.count() && !branched) {
    int columnIndex = indexesBranchingVars.at(i);
    
    if (!problem.isIntegerVariable(columnIndex)) {
      double lowerBound = 0.0;
      double upperBound = 1.0;
      QChar varPrefix = problem.getColumnPrefixName(columnIndex);
      
      // Nuevo nodo / problema
      Problem * newProblem = new Problem(problem);
      
      // Adici�n de la restricci�n con la variable = 0
      cout.precision(20);
      TRACE ("Subproblema: " << qPrintable(problem.getColumnName(columnIndex))
              << " = " << lowerBound <<
              ". Este subproblema fue generado ya que la variable "
              << qPrintable(problem.getColumnName(columnIndex))
              << " = " << problem.getVariable(columnIndex));
      addConstraintToProblem(newProblem, columnIndex, EQ, lowerBound);
      children.append(newProblem);
      
      // Nuevo nodo / problema
      newProblem = new Problem(problem);
      
      // Creaci�n de nodo con restricci�n de variable = 1
      TRACE ("Subproblema: " << qPrintable(problem.getColumnName(columnIndex)) 
             << " = " << upperBound);
      addConstraintToProblem(newProblem, columnIndex, EQ, upperBound);
      
      // Si es una variable ri (vereda m�s lejana), las dem�s ri son iguales a 0
      if (varPrefix == 'r' || varPrefix == 'R') {
        addMultipleConstraintsToProblem(newProblem, columnIndex, EQ, lowerBound);
      }
      children.append(newProblem);
      branched = true;
      newProblem = 0;
    }
    ++i;
  }
  
  return children;
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

void BranchAndBound::addMultipleConstraintsToProblem(Problem * problem,
                                                     const int & columnIndex,
                                                     const int & constrType,
                                                     const double & bound)
{
  for (int i = 0; i < indexesBranchingVars.count(); ++i) {
    int currentIndex = indexesBranchingVars.at(i);
    QChar currentPrefix = problem->getColumnPrefixName(currentIndex);
    bool isIntegerPrefix = currentPrefix == 'r' || currentPrefix == 'R';
    
    if (isIntegerPrefix && currentIndex != columnIndex)
      addConstraintToProblem(problem, currentIndex, EQ, bound);
  }
}

QString BranchAndBound::indexesBranchingVarsToString() const
{
  QString outString = "( ";
  
  foreach (int columnIndex, indexesBranchingVars)
      outString += originProblem->getColumnName(columnIndex) + " ";
  
  outString += ")";
  
  return outString;
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
    //    cout << qPrintable(problem.getColumnName(variableIndex)) << " = " << problem.getVariable(variableIndex) << ", ";
    ++i;
  }
  
  return isInteger;
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

int BranchAndBound::getIterationsCounter()
{
  return iterationsCounter - 1;
}

long long BranchAndBound::getTotalIterations()
{
//  cout << "relaxedIterations: " << relaxedIterations<< endl; ;
//  cout << "iterationsCounter: " << iterationsCounter<< endl;
  return (relaxedIterations + (long long)iterationsCounter);
}

int BranchAndBound::getNodesCounter()
{
  return nodesCounter;
}

long long BranchAndBound::getRelaxedIterations()
{
  return relaxedIterations;
}


