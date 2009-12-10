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

#include <utils/Problem.h>
#include <bab/BranchAndBound.h>


void lpsolveDemo()
{
  lprec *lp;
  lp = make_lp(0,4);
  
  
  cout << "\nAdición restricción 1"<< endl;
  str_add_constraint(lp, "3 2 2 1", LE, 4);
  print_lp(lp);
  
  cout << "\nAdición restricción 2"<< endl;
  str_add_constraint(lp, "0 4 3 1", GE, 3);
  print_lp(lp);
  
  cout << "\nAdición función objetivo"<< endl;
  str_set_obj_fn(lp, "2 3 -2 3");
  print_lp(lp);
  
  cout << "\nResolviendo... "<< endl;
  solve(lp);
  
  cout << "\n** ESTADO FINAL ** "<< endl;
  cout << "Función objetivo: "<< endl;
  print_objective(lp);
  cout << "\nSolución: "<< endl;
  print_solution(lp, 1);
  cout << "\nRestricciones: "<< endl;
  print_constraints(lp, 1);
  

  delete_lp(lp);
  
  
  cout << "\nTerminado exitosamente!! "<< endl;
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
  model = read_LP("data/models/example_int_01.lp", NORMAL, "Modelo Inicial");
  if (model) {
    cout << "Modelo leído correctamente." << endl;
//    print_lp(model);
  }
  
  Problem * problem = new Problem(model, "Problema original");
  
  BranchAndBound * bbObject = new BranchAndBound(problem, 10000);
  
  QList<int> varsBranching;
  varsBranching << 0 << 1;
  
//  solve(problem->getModel());
//  cout << problem->getVariable(1) << endl;
  
  
  
}

int main(int argc, char *argv[])
{
  
//  qDebug() << "Hola, esto es una prueba.\n";
//  defaultApp(argc, argv);
  testBranchAndBound();
//  Q_UNUSED(argc);
//  Q_UNUSED(argv);
//  lpsolveDemo();
  return 0;
}

