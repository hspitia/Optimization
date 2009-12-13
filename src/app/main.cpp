/**
 * @file main.cpp
 * @date 23/11/2009
 * @author He-.ctor Fabio Espitia Navarro <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
 * Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief 
 */

/* 
 *         File:  main.cpp
 *   Created on:  23/11/2009
 *       Author:  He-.ctor Fabio Espitia Navarro
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  Optimization
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#include <app/ApplicationController.h>
#include <gui/MainWindow.h>

#include <QtGui>
#include <QApplication>

#include <lpsolve/lp_lib.h>
#include <lpsolve/lp_fortify.h>

#include <iostream>
using namespace std;;

#include <utils/Utils.h>
#include <utils/Problem.h>
#include <bab/BranchAndBound.h>


void lpsolveDemo()
{
  lprec *lp;
  lp = make_lp(0,4);
  
  str_add_constraint(lp, "3 2 2 1", LE, 4);
  
  str_add_constraint(lp, "0 4 3 1", GE, 3);
  
  str_set_obj_fn(lp, "2 3 -2 3");
  
  solve(lp);
  
  delete_lp(lp);
}

int defaultApp(int argc, char *argv[])
{
  ApplicationController * app = new ApplicationController(argc, argv);
  app->getMainWindow()->show();
  return app->exec();
}

void testBranchAndBound()
{
  lprec * model;
//  model = read_LP("data/models/example_int_01.lp", NORMAL, "Modelo Inicial");
  model = read_LP("data/models/example_int_02.lp", NORMAL, "Modelo Inicial");
  if (model) {
    cout.precision(22);
  }
  
  Problem * problem = new Problem(model, "Problema original");
  
  BranchAndBound * bbObject = new BranchAndBound(problem, -10000);
  
  QList<int> varsBranching;
//  varsBranching << 0 << 1;
//  bbObject->setIndexesBranchingVars(varsBranching);
  
  Problem * bestSolution = bbObject->solveBb();
  lprec * solution = bestSolution->getModel();
}

void testBinaryBranchAndBound()
{
  lprec * model;
  model = read_LP("data/models/model_1d_01.lp", NORMAL, "Modelo Inicial");
  if (model) {
    cout.precision(22);
  }
  

  Problem * problem = new Problem(model, "Problema original");
  
  BranchAndBound * bbObject = new BranchAndBound(problem, 10000);

  Problem * bestSolution = bbObject->solveBb(BranchAndBound::BINARY_BRANCHING);

  if (bestSolution != 0) {
    lprec * solution = bestSolution->getModel();
  }
  else {
    cout << "\n\nOoooooppppssss!. Error"<< endl;
  }
}

int main(int argc, char *argv[])
{
  
//  qDebug() << "Hola, esto es una prueba.\n";
  defaultApp(argc, argv);
//  testBranchAndBound();
//  testBinaryBranchAndBound();
//  Q_UNUSED(argc);
//  Q_UNUSED(argv);
//  lpsolveDemo();
  return 0;
}

