/**
 * @file Problem.h
 * @date 5/12/2009
 * @author Hector <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
 * Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief 
 */

/* 
 *         File:  Problem.h
 *   Created on:  5/12/2009
 *       Author:  Hector
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  Optimization
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#ifndef PROBLEM_H_
#define PROBLEM_H_

// Qt
#include <QString>

// Lp solve
#include <lpsolve/lp_lib.h>

// Std
#include <cassert>
#include <iostream>

using namespace std;

// Project
#include <utils/Utils.h>


/**
 * 
 */
class Problem
{
  public:
    // Constructors
    Problem();
    Problem(lprec * model, const QString & id);
    Problem(const Problem & problemObject);
    
    // Copy operator
    Problem & operator=(const Problem & problemObject);
    
    // Destructor
    virtual ~Problem();
    
    // Methods
    bool getVariables(double * variables);
    bool addConstraint(double * row, int constrType, double rhValue);
    bool addConstraintex(int count, double * row, int * colno,
                         int constrType, double rhValue);
    bool addColumn(double * column);
    double getObjFunctionValue() const;
    int compareObjFunctionValueTo(const double & value) const;
    double getVariable(const int & columnIndex);
    bool isIntegerVariable(const int & columnIndex);
    
    // Access
    lprec * getModel() const;
    void setModel(lprec * model);
    QString getId();
    void setId(QString id);
    bool isFinished();
    void setFinished(bool finished);
    
  private:
    // Members
    lprec * model;
    QString id;
    bool finished;
};

#endif /* PROBLEM_H_ */
