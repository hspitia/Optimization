/**
 * @file ApplicationController.h
 * @date 23/11/2009
 * @author He-.ctor Fabio Espitia Navarro <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
 * Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief 
 */

/* 
 *         File:  ApplicationController.h
 *   Created on:  23/11/2009
 *       Author:  He-.ctor Fabio Espitia Navarro
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  Optimization
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#ifndef APPLICATIONCONTROLLER_H_
#define APPLICATIONCONTROLLER_H_

// Qt
#include <QApplication>
#include <QtCore/QList>
#include <QtCore/QPointF>

// Lp_solve
#include <lpsolve/lp_lib.h>

// Project
#include <gui/MainWindow.h>
#include <parser/FileParser.h>
#include <parser/ParametersSet.h>
#include <parser/Modeler.h>
#include <bab/BranchAndBound.h>
#include <utils/Problem.h>

#include <cmath>


// Cyclic reference 
class MainWindow;

class ApplicationController : public QApplication
{
  Q_OBJECT
    
  public:
    ApplicationController(int & argc, char ** argv);
    virtual ~ApplicationController();
    
    MainWindow * getMainWindow();
    ParametersSet * getParametersSet();
   
    bool loadNewProblem(const QString & filePath);
    bool solveProblem();
    
  private:
    MainWindow * mainWindow;
    ParametersSet * parametersSet;
    Problem * originProblem;
    SolutionSet solution;
    BranchAndBound * branchAndBound;
    
    QString getTextFromFile(const QString & fileName);
    QString makeResultsText(const int & timeElapsed);
    QString getTimeElapsed(const int & milliseconds);
    
};

#endif /* APPLICATIONCONTROLLER_H_ */
