/**
 * @file ParametersSet.cpp
 * @date 23/11/2009
 * @author He-.ctor Fabio Espitia Navarro <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
 * Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief 
 */

/* 
 *         File:  ParametersSet.cpp
 *   Created on:  23/11/2009
 *       Author:  He-.ctor Fabio Espitia Navarro
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  Optimization
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#include "ParametersSet.h"

ParametersSet::ParametersSet()
{
  this->regionSize       = 0;
  this->nTowns           = 0;
  this->townsNumbers     = QList<int>();
  this->townsCoordinates = QList<QPointF>();
}

ParametersSet::ParametersSet(const ParametersSet & parametersSetObject)
{
  this->regionSize       = parametersSetObject.regionSize;
  this->nTowns           = parametersSetObject.nTowns;
  this->townsNumbers     = parametersSetObject.townsNumbers;
  this->townsCoordinates = parametersSetObject.townsCoordinates;
}

ParametersSet::ParametersSet(int regionSize, int nTowns,
                             QList<int> townsNumbers,
                             QList<QPointF> townsCoordinates)
{
  this->regionSize       = regionSize;
  this->nTowns           = nTowns;
  this->townsNumbers     = townsNumbers;
  this->townsCoordinates = townsCoordinates;
}

ParametersSet & ParametersSet::operator=(const ParametersSet & 
                                         parametersSetObject)
{
  this->regionSize       = parametersSetObject.regionSize;
  this->nTowns           = parametersSetObject.nTowns;
  this->townsNumbers     = parametersSetObject.townsNumbers;
  this->townsCoordinates = parametersSetObject.townsCoordinates;
  
  return *this;
}

ParametersSet::~ParametersSet()
{
  // TODO Auto-generated destructor stub
}

int ParametersSet::getRegionSize()
{
  return regionSize;
}

void ParametersSet::setRegionSize(const int & regionSize)
{
  this->regionSize = regionSize;
}

int ParametersSet::getNTowns()
{
  return nTowns;
}

void ParametersSet::setNTowns(const int & nTowns)
{
  this->nTowns = nTowns;
}

QList<QPointF> ParametersSet::getTownsCoordinates()
{
  return townsCoordinates;
}

void ParametersSet::setTownsCoordinates(const QList<QPointF> & 
                                                schoolCoordinates)
{
  this->townsCoordinates = schoolCoordinates;
}

QList<int> ParametersSet::getTownsNumbers()
{
  return townsNumbers;
}

void ParametersSet::setTownsNumbers(const QList<int> & townsNumbers)
{
  this->townsNumbers = townsNumbers;
}
