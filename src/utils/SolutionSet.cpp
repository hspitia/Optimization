/**
* @file SolutionSet.cpp
* @date 16/12/2009
* @author He-.ctor Fabio Espitia Navarro <br>
* Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
* Computaci&oacute;n.<br>
* Santiago de Cali - Colombia
* @brief 
*/

/* 
 *         File:  SolutionSet.cpp
 *   Created on:  16/12/2009
 *       Author:  He-.ctor Fabio Espitia Navarro
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  GenomAMf
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#include "SolutionSet.h"

SolutionSet::SolutionSet()
{
  this->objectiveFunctionValue = 0.0;
  this->distances              = QMap<QString, double>();
  this->schoolPosition         = QPointF();
}

SolutionSet::SolutionSet(const double & objectiveFunctionValue, 
                         const QMap<QString, double> & distances,
                         const QPointF & schoolPosition)
{
  this->objectiveFunctionValue = objectiveFunctionValue;
  this->distances              = distances;
  this->schoolPosition         = schoolPosition;
}

SolutionSet::SolutionSet(const SolutionSet & solutionSetObject)
{
  this->objectiveFunctionValue = solutionSetObject.objectiveFunctionValue;
  this->distances              = solutionSetObject.distances;
  this->schoolPosition         = solutionSetObject.schoolPosition;
}

SolutionSet & SolutionSet::operator=(const SolutionSet & solutionSetObject)
{
  this->objectiveFunctionValue = solutionSetObject.objectiveFunctionValue;
  this->distances              = solutionSetObject.distances;
  this->schoolPosition         = solutionSetObject.schoolPosition;
  return *this;
}

SolutionSet::~SolutionSet()
{
  
}

QString SolutionSet::toString()
{
  QString outText = "";
  
  // Posición de la escuela
  outText += QString("- Ubicación de la escuela:      (%1, %2)\n")
               .arg(schoolPosition.x())
               .arg(schoolPosition.y());
               
  // Valor de la función objetivo
  outText += QString("- Valor de la función objetivo: %1\n")
                       .arg(objectiveFunctionValue);
  
  // Distancias entre la escuela y las veredas
  outText += "- Distancias entre la escuela y cada vereda:\n";
  QMap<QString, double>::const_iterator i = distances.constBegin();
  while (i != distances.constEnd()) {
    outText += QString("    %1: %2\n")
                               .arg(i.key())
                               .arg(i.value());  
    ++i;
  }
  
  return outText;
}

double SolutionSet::getObjectiveFunctionValue()
{
  return objectiveFunctionValue;
}

void SolutionSet::setObjectiveFunctionValue(double objectiveFunctionValue)
{
  this->objectiveFunctionValue = objectiveFunctionValue;
}

QMap<QString, double> SolutionSet::getDistances()
{
  return distances;
}

void SolutionSet::setDistances(QMap<QString, double> distances)
{
  this->distances = distances;
}

QPointF SolutionSet::getSchoolPosition()
{
  return schoolPosition;
}

void SolutionSet::setSchoolPosition(QPointF schoolPosition)
{
  this->schoolPosition = schoolPosition;
}

bool SolutionSet::isEmpty()
{
  return distances.isEmpty();
}
