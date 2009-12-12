#ifndef MODELER_H
#define MODELER_H

#include <QtCore/QList>
#include <QtCore/QPointF>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "ParametersSet.h"

class Modeler
{
  public:
    Modeler(const ParametersSet & parametersSetObject);
    void generateModel(bool withBin = false);
//    QString writeModel(QString fileName);
    bool writeModel(QString fileName);

  private:
    // Attributes
    int nTowns;
    int regionSize;
    double bigM;
    QList<QPointF> townsCoordinates;
    QList<int> townsNumbers;
    QString obj;
    QString M;
    QString ints;
    QString model;

    // Methods
    void initialize();
    QString printPoints();
    void model2D(bool withBin);
    void calculateConditions();
    void calculateDistances();
    QString qpointToString(const QPointF & p);
    
};

#endif // MODELER_H
