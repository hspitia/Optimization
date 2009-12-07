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

#include "BranchAndBound.h"

BranchAndBound::BranchAndBound()
{
  this->originProblem   = 0;
  this->bestSolution    = 0;
  this->problemsToSolve = QStack<Problem *>();
  this->bound           = 0;
}

BranchAndBound::BranchAndBound(Problem * originProblem, double bound)
{
  this->originProblem   = originProblem;
  this->bestSolution    = 0;
  this->problemsToSolve = QStack<Problem *>();
  this->bound           = bound;
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
  if (originProblem->ProblemType == Problem::MAXIMIZATION)
    solveBbMax();
  else if (originProblem->ProblemType == Problem::MINIMIZATION)
    solveBbMin();
}

Problem * BranchAndBound::solveBbMax()
{
  problemsToSolve.push(originProblem);
  
  while (!problemsToSolve.isEmpty()) {
    Problem * currentProblem = problemsToSolve.pop();
    lprec * model = currentProblem->getModel();
    int result = solve(model);
    
    bool feasible = result == 0 || result == 1;
    bool belowBound = currentProblem->isBelowBound(bound);
    bool integerSolution = currentProblem->isIntegerSolution();
    
    if (!feasible || belowBound || integerSolution) {
      currentProblem->setFinished(true);
      
      if (integerSolution && currentProblem->isOverBound(bound)) {
          bound = currentProblem->getObjFunctionValue();
          bestSolution = currentProblem;
      }
    }
    else {
      QList<Problem *> children = branch(*currentProblem);
      foreach (Problem * p, children)
          problemsToSolve.push(p);
    }
  }
  return bestSolution;
}

Problem * BranchAndBound::solveBbMin()
{
  problemsToSolve.push(originProblem);
  
  while (!problemsToSolve.isEmpty()) {
    Problem * currentProblem = problemsToSolve.pop();
    lprec * model = currentProblem->getModel();
    int result = solve(model);
    
    bool feasible = result == 0 || result == 1;
    bool overBound = currentProblem->isOverBound(bound);
    bool integerSolution = currentProblem->isIntegerSolution();
    
    if (!feasible || overBound || integerSolution) {
      currentProblem->setFinished(true);
      
      if (integerSolution && currentProblem->isBelowBound(bound)) {
          bound = currentProblem->getObjFunctionValue();
          bestSolution = currentProblem;
      }
      
    }
    else {
      QList<Problem *> children = branch(*currentProblem);
      foreach (Problem * p, children)
          problemsToSolve.push(p);
    }
  }
  return bestSolution;
}

QList<Problem *> BranchAndBound::branch(const Problem & problem)
{
  QList<Problem *> children;
  
  int i = 0;
  bool branched = false;
  
  while (i < indexesBranchingVars.count() && !branched){
    if (!problem.isIntegerVariable(i)) {
      double lowerBound = floor(problem.getVariable(i));
      double upperBound = ceil(problem.getVariable(i));
      
      Problem * newProblem = new Problem(problem);
      addConstraintToProblem(newProblem, i, LE, lowerBound);
      children.append(newProblem);
      
      newProblem = new Problem(problem);
      addConstraintToProblem(newProblem, i, GE, upperBound);
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
  colno[0] = columnIndex;
  
  double sparserow[1];
  sparserow[0] = 1.0;
  
  problem->addConstraintex(1, sparserow, colno, constrType, bound);
}

bool BranchAndBound::isOverBound(const Problem & problem)
{
  int result = problem.compareObjFunctionValueTo(bound);
  return result == 1;
}

bool BranchAndBound::isBelowBound(const Problem & problem)
{
  int result = problem.compareObjFunctionValueTo(bound);
  return result == -1;
}

//bool BranchAndBound::isIntegerSolution(const Problem & problem)
//{
//  int i = 0;
//  bool isInteger = true; 
//  
//  while (i < indexesBranchingVars.count() && isInteger) {
//    int variableIndex = indexesBranchingVars.at(i);
//    integer = problem.isIntegerVariable(variableIndex);
//  }
//  
//  if (isInteger)
//    return true;
//
//  return false;
//}

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
