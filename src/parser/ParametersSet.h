/**
 * @file ParametersSet.h
 * @date 23/11/2009
 * @author He-.ctor Fabio Espitia Navarro <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
 * Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief 
 */

/* 
 *         File:  ParametersSet.h
 *   Created on:  23/11/2009
 *       Author:  He-.ctor Fabio Espitia Navarro
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  Optimization
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#ifndef PARAMETERSSET_H_
#define PARAMETERSSET_H_

// Qt
#include <QtCore/QList>
#include <QtCore/QPointF>

/**
 * 
 */
class ParametersSet
{
  public:
    ParametersSet();
    ParametersSet(const ParametersSet & parametersSetObject);
    ParametersSet(int regionSize, int nTowns,
                  QList<int> schoolNumbers,
                  QList<QPointF> townsCoordinates);
    ParametersSet & operator=(const ParametersSet & parametersSetObject);
    virtual ~ParametersSet();
    
    int getNTowns() const;
    void setNTowns(const int & nTowns);
    int getRegionSize() const;
    void setRegionSize(const int & regionSize);
    QList<QPointF> getTownsCoordinates() const;
    void setTownsCoordinates(const QList<QPointF> & schoolCoordinates);
    QList<int> getTownsNumbers() const;
    void setTownsNumbers(const QList<int> & townsNumbers);
    
  private:
    int nTowns;
    int regionSize;
    QList<QPointF> townsCoordinates;
    QList<int> townsNumbers;
    
};

#endif /* PARAMETERSSET_H_ */
