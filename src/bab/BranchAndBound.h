/**
 * @file BranchAndBound.h
 * @date 5/12/2009
 * @author Hector <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
 * Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief 
 */

/* 
 *         File:  BranchAndBound.h
 *   Created on:  5/12/2009
 *       Author:  Hector
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  Optimization
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#ifndef BRANCHANDBOUND_H_
#define BRANCHANDBOUND_H_
// Qt
#include <QtCore/QStack>
#include <QtCore/QList>

// Project
#include <utils/tree.h>
#include <utils/Problem.h>
#include <utils/Utils.h>

// Std
#include <iostream>
#include <cmath>

using namespace std;

/**
 * 
 */
class BranchAndBound
{
  public:
    enum BranchStrategy
    {
      DFS
    };
    
    enum BranchingType
    {
      INTEGER_BRANCHING, BINARY_BRANCHING
    };
    
    BranchAndBound();
    BranchAndBound(Problem * originProblem, double bound);
    virtual ~BranchAndBound();
    
    Problem * getBestSolution();
    void setBestSolution(Problem * bestSolution);
    QStack<Problem *> getProblemsToSolve();
    void setProblemsToSolve(QStack<Problem *> problemsToSolve);
    Problem * getOriginProblem();
    void setOriginProblem(Problem * originProblem);
    Problem * solveBb(BranchingType branchingType = INTEGER_BRANCHING);
    Problem * solveBbMax(BranchingType branchingType);
    Problem * solveBbMin(BranchingType branchingType);
    double getBound();
    void setBound(double bound);
    QList<int> getIndexesBranchingVars();
    void setIndexesBranchingVars(QList<int> indexesBranchingVars);
    QString indexesBranchingVarsToString() const;
    int getIterationsCounter();
    int getNodesCounter();
    long long getRelaxedIterations();
    long long getTotalIterations();
    
  private:
    Problem * originProblem;
    Problem * bestSolution;
    QStack<Problem *> problemsToSolve;
    double bound;
    QList<int> indexesBranchingVars;
    int iterationsCounter;
    long long relaxedIterations;
    int nodesCounter;
    
    void initIndexesBranchingVars();
    
    bool isOverBound(const Problem & problem);
    bool isBelowBound(const Problem & problem);
    bool isIntegerSolution(const Problem & problem);
    QList<Problem *> branch(const Problem & problem, BranchingType branchType);
    QList<Problem *> integerBranching(const Problem & problem);
    QList<Problem *> binaryBranching(const Problem & problem);
    void addConstraintToProblem(Problem * problem, 
                                const int & columnIndex,
                                const int & constrType,
                                const double & bound);
    void addMultipleConstraintsToProblem(Problem * problem,
                                         const int & columnIndex,
                                         const int & constrType,
                                         const double & bound);
};

#endif /* BRANCHANDBOUND_H_ */
