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

// Project
#include <gui/MainWindow.h>
#include <parser/FileParser.h>
#include <parser/ParametersSet.h>


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
    
  private:
    MainWindow * mainWindow;
    ParametersSet * parametersSet;
    
};

#endif /* APPLICATIONCONTROLLER_H_ */
