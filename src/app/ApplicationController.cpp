/**
 * @file ApplicationController.cpp
 * @date 23/11/2009
 * @author He-.ctor Fabio Espitia Navarro <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
 * Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief 
 */

/* 
 *         File:  ApplicationController.cpp
 *   Created on:  23/11/2009
 *       Author:  He-.ctor Fabio Espitia Navarro
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  Optimization
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#include "ApplicationController.h"


ApplicationController::ApplicationController(int & argc, char ** argv):
  QApplication(argc, argv), 
  mainWindow(new MainWindow(this))
{
  parametersSet = 0;

}

ApplicationController::~ApplicationController()
{
  if (parametersSet != 0)
    delete parametersSet;
  
  parametersSet = 0;
}

bool ApplicationController::loadNewProblem(const QString & filePath)
{
  FileParser * fileParser = new FileParser();
  bool succes = fileParser->parseFile(filePath);
  
  if (!succes)
    return false;
  
  parametersSet = new ParametersSet(*(fileParser->getParametersSet()));
  delete fileParser;
  /* ************** DATA VERIFICATION ***************** */
  /*
  cout << "DEBUG - BEGIN - ApplicationController::52 - Data Verification" << endl;
  cout << "regionSize: " << parametersSet->getRegionSize() << endl;
  cout << "nSchools:   " << parametersSet->getNSchools() << endl;
  for (int i = 0; i < parametersSet->getNSchools(); ++i) {
    cout << parametersSet->getSchoolsNumbers().at(i) << " " 
         << parametersSet->getSchoolCoordinates().at(i).x() << " " 
         << parametersSet->getSchoolCoordinates().at(i).x() << endl; 
  }
  cout << "DEBUG - END - ApplicationController:60 - Data Verification" << endl;
  */
  /* ************************************************** */
  return true; 
}

MainWindow * ApplicationController::getMainWindow()
{
  return mainWindow;
}

ParametersSet * ApplicationController::getParametersSet()
{
  return parametersSet;
}
