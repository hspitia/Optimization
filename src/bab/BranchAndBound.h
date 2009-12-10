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
    
    BranchAndBound();
    BranchAndBound(Problem * originProblem, double bound);
    virtual ~BranchAndBound();
    
    Problem * getBestSolution();
    void setBestSolution(Problem * bestSolution);
    QStack<Problem *> getProblemsToSolve();
    void setProblemsToSolve(QStack<Problem *> problemsToSolve);
    Problem * getOriginProblem();
    void setOriginProblem(Problem * originProblem);
    Problem * solveBb();
    Problem * solveBbMax();
    Problem * solveBbMin();
    double getBound();
    void setBound(double bound);
    QList<int> getIndexesBranchingVars();
    void setIndexesBranchingVars(QList<int> indexesBranchingVars);
    
  private:
    Problem * originProblem;
    Problem * bestSolution;
    QStack<Problem *> problemsToSolve;
    double bound;
    QList<int> indexesBranchingVars;
    
    bool isOverBound(const Problem & problem);
    bool isBelowBound(const Problem & problem);
    QList<Problem *> branch(const Problem & problem);
    void addConstraintToProblem(Problem * problem, 
                                const int & columnIndex,
                                const int & constrType,
                                const double & bound);
    void addMultipleConstraintsToProblem(Problem * problem,
                                         const int & columnIndex,
                                         const QString &
                                         colNamePrefix, 
                                         const int & constrType,
                                         const double & bound);
};

#endif /* BRANCHANDBOUND_H_ */
