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

bool Problem::getVariables(double variables[], int & size)
{
//  get_variables(lprec *lp, REAL * variables);
  size = get_Ncolumns(model);
  return get_variables(model, variables);
}

int Problem::getNColumns() const
{
  return get_Ncolumns(model);
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
//  double x1 = getVariable(0);
//  double x2 = getVariable(1);
//  double obj = (5 * x1) + (4 * x2);
//  cout.precision(30);
//  cout << "\n\nObj calculada: " << obj << endl;
//  cout << "floor obj: " << floor(obj) << endl;
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
  
  bool condition = columnIndex >= 0 && columnIndex < size;
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
//  bool isInteger = true;
//  int size = get_Ncolumns(model); 
//  double variables[size];
//  if (get_variables(model, variables)){
//    int i = 0;
//    while (i < size && isInteger) {
//      isInteger = utils::isInteger(variables[i]);
//    }
//  }
//  
//  return isInteger;
//  cout <<__LINE__ << "\n\t" << "SOL in problem: " << getObjective();
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

QString Problem::getColumnName(const int & columnIndex) const
{
  int size = get_Ncolumns(model);
  bool condition = columnIndex >= 0 && columnIndex < size;
  
  if (!condition) {
    cout << "ERROR!! Assert. Out of bounds in getColumnName. "
         << " On line " << __LINE__ + 2
         << " in file " << __FILE__ << "\n";
    assert(condition);
  }
  
  QString colName = QString(get_col_name(model, columnIndex + 1));
  return colName;
}

QChar Problem::getColumnPrefixName(const int & columnIndex) const
{
  return getColumnName(columnIndex).at(0);
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
