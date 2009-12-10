/**
 * @file Problem.cpp
 * @date 5/12/2009
 * @author Hector <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
 * Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief 
 */

/* 
 *         File:  Problem.cpp
 *   Created on:  5/12/2009
 *       Author:  Hector
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  GenomAMf
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#include "Problem.h"

Problem::Problem()
{
  this->model    = 0;
  this->id       = "";
  this->finished = false;

}

Problem::Problem(lprec * model, const QString & id)
{
  this->model    = model;
  this->id       = id;
  this->finished = false;
}

Problem::Problem(const Problem & problemObject)
{
  this->model    = copy_lp(problemObject.model);
  this->id       = problemObject.id;
  this->finished = problemObject.finished;
}

Problem & Problem::operator=(const Problem & problemObject)
{
  this->model    = copy_lp(problemObject.model);
  this->id       = problemObject.id;
  this->finished = problemObject.finished;
  
  return *this;
}

Problem::~Problem()
{
  if (model)
    delete_lp(model);
}

bool Problem::getVariables(double * variables)
{
//  get_variables(lprec *lp, REAL * variables);
  return get_variables(model, variables);
}

bool Problem::addConstraint(double * row, int constrType, double rhValue)
{
//  add_constraint  (lprec *lp, REAL *row, int constr_type, REAL rh);
  set_add_rowmode(model, true);
  bool result = add_constraint(model, row, constrType, rhValue);
  set_add_rowmode(model, false);
  
  return result;
}

bool Problem::addConstraintex(int count, double * row, int * colno, 
                              int constrType, double rhValue)
{
//  add_constraintex(lprec *lp, int count, REAL *row, int *colno, int constr_type, REAL rh);
  set_add_rowmode(model, true);
  bool result = add_constraintex(model, count, row, colno, constrType, rhValue);
  set_add_rowmode(model, false);
  
  return result;
}

bool Problem::addColumn(double * column)
{
//  add_column(lprec *lp, REAL *column);
  return add_column(model, column);
}

double Problem::getObjective() const
{
  return get_objective(model);
}

int Problem::compareObjectiveTo(const double & value) const
{
  double objFunctionValue = getObjective();
  
  if (objFunctionValue > value)
    return 1;
  if (objFunctionValue < value)
    return -1;
  
  return 0;
}

double Problem::getVariable(const int & columnIndex) const
{
  int size = get_Ncolumns(model);
  double variables[size];
  
  bool condition = columnIndex > 0 && columnIndex < size;
  if (!condition) {
    cout << "ERROR!! Assert. Out of bounds. "
         << " On line " << __LINE__ 
         << " in file " << __FILE__  << "\n";
    assert(condition);
  }
  
  get_variables(model, variables);
  double variable = variables[columnIndex];
  
  return variable;
}

bool Problem::isIntegerVariable(const int & columnIndex) const
{
  double variable = getVariable(columnIndex);
  return utils::isInteger(variable);
}

bool Problem::isIntegerSolution() const
{
  return utils::isInteger(getObjective());
}

bool Problem::isOverBound(const double & bound)
{
  return compareObjectiveTo(bound) == 1;
}

bool Problem::isBelowBound(const double & bound)
{
  return compareObjectiveTo(bound) == -1;
}

bool Problem::isMaximization()
{
  return is_maxim(model);
}

QString Problem::getColumnName(const int & columnIndex)
{
  
}

lprec * Problem::getModel() const
{
  return model;
}

void Problem::setModel(lprec * model)
{
  this->model = model;
}

QString Problem::getId()
{
  return id;
}

void Problem::setId(QString id)
{
  this->id = id;
}

bool Problem::isFinished()
{
  return finished;
}

void Problem::setFinished(bool finished)
{
  this->finished = finished;
}
