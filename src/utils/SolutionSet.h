/**
 * @file SolutionSet.h
 * @date 16/12/2009
 * @author He-.ctor Fabio Espitia Navarro <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
 * Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief 
 */

/* 
 *         File:  SolutionSet.h
 *   Created on:  16/12/2009
 *       Author:  He-.ctor Fabio Espitia Navarro
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  Optimization
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#include <QMap>
#include <QString>
#include <QPointF>



#ifndef SOLUTIONSET_H_
#define SOLUTIONSET_H_

/**
 * 
 */
class SolutionSet
{
  public:
    SolutionSet();
    SolutionSet(const double & objectiveFunctionValue, 
                const QMap<QString, double> & distances,
                const QPointF & schoolPosition);
    SolutionSet(const SolutionSet & solutionSetObject);
    SolutionSet & operator=(const SolutionSet & solutionSetObject);
    virtual ~SolutionSet();
    double getObjectiveFunctionValue();
    void setObjectiveFunctionValue(double objectiveFunctionValue);
    QMap<QString, double> getDistances();
    void setDistances(QMap<QString, double> distances);
    QPointF getSchoolPosition();
    void setSchoolPosition(QPointF schoolPosition);
    QString toString();
    bool isEmpty();
    
  private:
    double objectiveFunctionValue;
    QMap<QString, double> distances;
    QPointF schoolPosition;
    
};

#endif /* SOLUTIONSET_H_ */
