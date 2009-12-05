/**
 * @file FileParser.cpp
 * @date 23/11/2009
 * @author He-.ctor Fabio Espitia Navarro <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
 * Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief 
 */

/* 
 *         File:  FileParser.cpp
 *   Created on:  23/11/2009
 *       Author:  He-.ctor Fabio Espitia Navarro
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  Optimization
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#include "FileParser.h"

FileParser::FileParser()
{
  this->parametersSet = 0;
}

FileParser::~FileParser()
{
  if (parametersSet != 0)
    delete parametersSet;
  
  parametersSet = 0;
}

bool FileParser::parseFile(const QString & filePath)
{
  QFile file(filePath);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return false;
  
  QTextStream textStream(&file);
  parametersSet = new ParametersSet();
  QList<QPointF> coordinates;;
  QList<int> numbers;
  int parametersPerLine = 3;
  int currentLine = 1;
  
  while (!textStream.atEnd()) {
    QString line = textStream.readLine();
    bool ok = true;
    if (currentLine == 1) {
      int regionSize = line.toInt(&ok, 10);
      if (!ok)
        return false;
      parametersSet->setRegionSize(regionSize);
    }
    else if (currentLine == 2) {
      int nTowns = line.toInt(&ok, 10);
      if (!ok)
        return false;
      parametersSet->setNTowns(nTowns);
    }
    else if (currentLine > 2) {
      QStringList tokens = line.split(" ",QString::SkipEmptyParts);
      if (tokens.count() >= parametersPerLine) {
        int number = tokens.at(0).toInt(&ok, 10);
        if (!ok) 
          return false;
        
        numbers << number;
        double xCoordinate = tokens.at(1).toDouble(&ok);
        if (!ok) 
          return false;
        
        double yCoordinate = tokens.at(2).toDouble(&ok);
        if (!ok) 
          return false;
        
        coordinates << QPointF(xCoordinate, yCoordinate);
      }
      else
        return false;
    }
    ++currentLine;
  }
  
  parametersSet->setTownsNumbers(numbers);
  parametersSet->setTownsCoordinates(coordinates);
  
  return true;
}


ParametersSet * FileParser::getParametersSet()
{
  return parametersSet;
}


