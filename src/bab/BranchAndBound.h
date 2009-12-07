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

// Project
#include <utils/tree.h>
#include <utils/Problem.h>
#include <utils/Utils.h>


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
    
    double getBound();
    
    void setBound(double bound);
    
  private:
//    tree<Problem> problemsTree;
    Problem * originProblem;
    Problem * bestSolution;
    QStack<Problem *> problemsToSolve;
    double bound;
    
    bool isOverBound(const Problem & problem);
    bool isBelowBound(const Problem & problem);
    bool isIntegerSolution(const Problem & problem);
    QList<Problem *> branch(const Problem & problem);
};

#endif /* BRANCHANDBOUND_H_ */
