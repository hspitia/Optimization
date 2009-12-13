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
  parametersSet  = 0;
  originProblem  = 0;
  branchAndBound = 0;
  solution       = 0;
}

ApplicationController::~ApplicationController()
{
  if (parametersSet != 0)
    delete parametersSet;
  
  parametersSet  = 0;
  
  if (originProblem != 0)
    delete originProblem;
  
  originProblem  = 0;
  
  if (branchAndBound != 0)
    delete branchAndBound;
  
  branchAndBound = 0;
  
  if (solution != 0)
    delete solution;
  
  solution       = 0;
}

bool ApplicationController::loadNewProblem(const QString & filePath)
{
  QString modelFileName = "tmp/model.lp" ;
  FileParser * fileParser = new FileParser();
  bool succes = fileParser->parseFile(filePath);
  
  if (!succes)
    return false;
  
  parametersSet = new ParametersSet(*(fileParser->getParametersSet()));
  
  Modeler * modeler = new Modeler(*parametersSet);
//  modeler->generateModel(true);
  modeler->generateModel();
  succes = modeler->writeModel(modelFileName);
  
  delete fileParser;
  delete modeler;
  
  if(!succes)
    return false;
  
  lprec * model;
  model = read_LP(modelFileName.toAscii().data(), NORMAL, "Modelo Inicial");
  if (model) {
    originProblem = new Problem(model, "Problema original");
    
    double bound = parametersSet->getRegionSize() * 2 * 100;
    branchAndBound = new BranchAndBound(originProblem, bound);
    
    mainWindow->setUpScene(parametersSet->getRegionSize(),
                           parametersSet->getTownsNumbers(),
                           parametersSet->getTownsCoordinates());
    mainWindow->updateModelTab(getTextFromFile(modelFileName));
    mainWindow->updateInputFileTab(getTextFromFile(filePath));
  }
  else
    return false;
    
  return true; 
}

bool ApplicationController::solveProblem()
{
  solution = branchAndBound->solveBb(BranchAndBound::BINARY_BRANCHING);
  if (solution) {
    // TODO - enviar resultados a mainWindow
    lprec * model = solution->getModel();
    mainWindow->paintSchool(QPointF(solution->getVariable(parametersSet->getNTowns()+1),solution->getVariable(parametersSet->getNTowns()+4)));
  }
  else
    return false;
    
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

QString ApplicationController::getTextFromFile(const QString & fileName)
{
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return QString();
  
  QTextStream textStream(&file);
  QString text;
  
  while (!textStream.atEnd()) {
    text += textStream.readLine() + "\n";
  }
  
  return text;
}
