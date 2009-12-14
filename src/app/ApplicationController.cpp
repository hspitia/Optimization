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
  solution = 0;
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
  
  if (solution != 0)
    delete solution;
  
  solution = 0;
}

bool ApplicationController::loadNewProblem(const QString & filePath)
{
  QString modelFileName = "tmp/model.lp";
  FileParser * fileParser = new FileParser();
  bool succes = fileParser->parseFile(filePath);
  
  if (!succes)
    return false;

  parametersSet = new ParametersSet(*(fileParser->getParametersSet()));
  
  Modeler * modeler = new Modeler(*parametersSet);
//    modeler->generateModel(true);
  modeler->generateModel();
  succes = modeler->writeModel(modelFileName);
  
  delete fileParser;
  delete modeler;
  
  if (!succes)
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
  
//  Problem * bestSolution = branchAndBound->solveBb(BranchAndBound::BINARY_BRANCHING);
//  solution = bestSolution;
//  solution = new Problem (*bestSolution);
  
//  delete branchAndBound;
  
  solve(solution->getModel());
  
  if (solution) {
    // TODO - enviar resultados a mainWindow
    mainWindow->updateResultsTab(makeResultsText());
    mainWindow->paintSchool(getSchoolPosition());
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

QPointF ApplicationController::getSchoolPosition()
{
  QPointF schoolPosition;
  
  if (solution) {
    int nTowns = parametersSet->getNTowns();
    double xSchoolCoordinate = solution->getVariable(nTowns + 1);
    double ySchoolCoordinate = solution->getVariable(nTowns + 4);
    schoolPosition = QPointF(xSchoolCoordinate, ySchoolCoordinate);
  }
  
  return schoolPosition;
}

QString ApplicationController::makeResultsText()
{
  QString outText = "";
  QPointF schoolPosition = getSchoolPosition();
  
  if (solution) {
    // Posición de la escuela 
    outText += "SOLUCIÓN ENCONTRADA\n";
    outText += QString("- Ubicación de la escuela:      (%1, %2)\n")
               .arg(schoolPosition.x())
               .arg(schoolPosition.y());
               
    // Valor de la función objetivo
    outText += QString("- Valor de la función objetivo: %1\n")
               .arg(solution->getObjective());
    
    outText += "\n";
            
    // Total Iteraciones
    outText += QString("- Total iteraciones: %1\n")
               .arg(branchAndBound->getIterationsCounter());
            
    // Total Nodos
    outText += QString("- Total nodos      : %1\n")
               .arg(branchAndBound->getNodesCounter());
    
    outText += "\n";
    
    outText += getDistancesResultText();
  }
  
  return outText;
}

QString ApplicationController::getDistancesResultText()
{
  QString outText = "- Distancias entre la escuela y cada vereda:\n";
  int size = solution->getNColumns();
  double variables[size];
  cout<< boolalpha << solution->getVariables(variables, size) << endl;
  
  int dist = parametersSet->getNTowns() + 6;
  int index = dist;
  
  for (int i = 0; i < parametersSet->getNTowns(); ++i) {
    index = dist + (5 * i);
    outText += QString("    %1: %2\n")
               .arg(solution->getColumnName(index))
               .arg(variables[index]);
  }
  
  return outText;
}


























