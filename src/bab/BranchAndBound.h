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
      Normal_Strategy
    };
    
    BranchAndBound();
    virtual ~BranchAndBound();
    
  private:
    tree<Problem> problemsTree;
};

#endif /* BRANCHANDBOUND_H_ */
