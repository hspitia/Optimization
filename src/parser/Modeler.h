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
    enum ModelType{
      NORMAL_MODEL, ALTERNATIVE_MODEL 
    };
    
    Modeler(const ParametersSet & parametersSetObject);
    void generateModel(const int & modelType = NORMAL_MODEL, bool withBin = false);
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
//    void model2D(bool withBin);
    void model2D(const int & modelType, bool withBin);
    void calculateConditions();
    void calculateDistances(bool withBin);
    QString qpointToString(const QPointF & p);
    
    void calculateConditionsAlternative();
    void calculateDistancesAlternative(bool withBin);
    
};

#endif // MODELER_H
