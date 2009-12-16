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

ApplicationController::ApplicationController(int & argc, char ** argv) :
  QApplication(argc, argv), mainWindow(new MainWindow(this))
{
  parametersSet = 0;
  originProblem = 0;
  branchAndBound = 0;
//  solution = 0;
  solution = SolutionSet();
}

ApplicationController::~ApplicationController()
{
  if (parametersSet != 0)
    delete parametersSet;
  
  parametersSet = 0;
  
  if (originProblem != 0)
    delete originProblem;
  
  originProblem = 0;
  
  if (branchAndBound != 0)
    delete branchAndBound;
  
  branchAndBound = 0;
//  
//  if (solution != 0)
//    delete solution;
//  
//  solution = 0;
}

bool ApplicationController::loadNewProblem(const QString & filePath)
{
  QString modelFileName = "tmp/model.lp";
  FileParser * fileParser = new FileParser();
  bool succes = fileParser->parseFile(filePath);
  
  if (!succes){
    cout << "Error de lectura de archivo." << endl;
    return false;
  }

  parametersSet = new ParametersSet(*(fileParser->getParametersSet()));
  
  Modeler * modeler = new Modeler(*parametersSet);
//    modeler->generateModel(true);
  int modelType = mainWindow->getModelType();
  modeler->generateModel(modelType);
  succes = modeler->writeModel(modelFileName);
  
  delete fileParser;
  delete modeler;
  
  if (!succes){
    cout << "Error de escritura de archivo de modelo lp." << endl;
    return false;
  }

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
  else {
    cout << "Error de lectura de archivo de modelo lp." << endl;
    return false;
  }
  
  return true;
}

bool ApplicationController::solveProblem()
{
  QTime timer;
  timer.restart();
  solution = branchAndBound->solveBb(BranchAndBound::BINARY_BRANCHING);
  int timeElapsed = timer.elapsed();
  
//  if (solution) {
  if (!solution.isEmpty()) {
    mainWindow->updateResultsTab(makeResultsText(timeElapsed));
    mainWindow->paintSchool(solution.getSchoolPosition());
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

QString ApplicationController::makeResultsText(const int & timeElapsed)
{
  QString outText = "";
//  QPointF schoolPosition = getSchoolPosition();
//  QPointF schoolPosition = solution->getSchoolPosition();
  QPointF schoolPosition = solution.getSchoolPosition();
  
//  if (solution) {
  if (!solution.isEmpty()) {
    outText += "SOLUCIÓN ENCONTRADA\n\n";

    outText += solution.toString();
    
    outText += "\n";
    // Iteraciones
    outText += QString("- Iteraciones solución relajada: %1\n")
               .arg(branchAndBound->getRelaxedIterations());
            
    outText += QString("- Iteraciones Branch and Bound : %1\n")
               .arg(branchAndBound->getIterationsCounter());
    
    outText += QString("- Total Iteraciones            : %1\n")
               .arg(branchAndBound->getTotalIterations());
            
    // Total Nodos
    outText += QString("- Total nodos en B&B           : %1\n")
               .arg(branchAndBound->getNodesCounter());
    
    outText += "\n";
    
    outText += "- Tiempo de solución: " + getTimeElapsed(timeElapsed);
  }
  
  return outText;
}

QString ApplicationController::getTimeElapsed(const int & milliseconds)
{
  QString outText = "";
  double min  = 0;
  double sec  = 0;
  
  if (milliseconds >= 1000) {
    sec  = ((double)milliseconds) / 1000.0;
    if(sec >= 60.0){
      min = sec / 60.0;
      sec = min / 60.0;
      outText += QString("%1 min, ").arg((int)floor(min));
    }
    outText += QString("%1 seg\n").arg(sec);
  }
  else 
    outText += QString("%1 ms\n").arg(milliseconds);
  
  return outText;
}
























