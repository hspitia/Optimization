#include "Modeler.h"

//Modeler::Modeler(ParametersSet parametersSetObject)
Modeler::Modeler(const ParametersSet & parametersSetObject)
{
  regionSize = parametersSetObject.getRegionSize();
  nTowns = parametersSetObject.getNTowns();
  townsNumbers = parametersSetObject.getTownsNumbers();
  townsCoordinates = parametersSetObject.getTownsCoordinates();
  initialize();
}

void Modeler::initialize()
{
  obj = "// Funcion Objetivo\n";
  obj += "min: L";
  model = "// Calculo de las Distancias entre la escuela y las veredas\n";
  //bin="// Restricciones Binarias\n";
  ints = "// Restricciones Binarias\n";
  bigM = regionSize * 2;
  model = "// Puntos\n// " + printPoints() + "\n\n" + model;
  M = QString::number(bigM);
}

void Modeler::generateModel(const int & modelType, bool withBin)
{
  model2D(modelType, withBin);
  //return model;
}

QString Modeler::qpointToString(const QPointF & p)
{
  QString x = QString::number(p.x());
  QString y = QString::number(p.y());
  return "[" + x + "," + y + "]";
}

QString Modeler::printPoints()
{
  QString out = "{" + qpointToString(townsCoordinates[0]);
  for (int i = 1; i < townsCoordinates.size(); i++) {
    out += " , " + qpointToString(townsCoordinates[i]);
  }
  out += "}";
  return out;
}

void Modeler::model2D(const int & modelType, bool withBin)
{
////  if (withBin) {
//    calculateDistances(withBin);
//    model += "\n";
//    calculateConditions();
//    model = obj + "\n" + model + "\n" + ints;
////  }
////  else {
////    calculateDistances(withBin);
////    model += "\n";
////    calculateConditions();
////    model = obj + "\n" + model;
////    model = obj + "\n" + model + "\n" + ints;
////  }

  if (modelType == NORMAL_MODEL) {
    calculateDistances(withBin);
    model += "\n";
    calculateConditions();
    model = obj + "\n" + model + "\n" + ints;
  }
  else if (modelType == ALTERNATIVE_MODEL) {
    calculateDistancesAlternative(withBin);
    model += "\n";
    calculateConditionsAlternative();
    model = obj + "\n" + model + "\n" + ints;
  }
  
}

void Modeler::calculateDistances(bool withBin)
{
  int size = townsCoordinates.size();
  for (int di = 0; di < size; di++) {
    QString i = QString::number(di + 1);
    QString elmX = QString::number(townsCoordinates[di].x());
    QString elmY = QString::number(townsCoordinates[di].y());
    
    model += "// Distancia de la escuela a " + i + "\n";
    model += "// Distancia en X\n";
    model += "dx" + i + " - ex + " + elmX + " - " + M + " Nx" + i + " >= -" + M
            + ";\n";
    model += "dx" + i + " - ex + " + elmX + " + " + M + " Nx" + i + " <= " + M
            + ";\n";
    model += "dx" + i + " - " + elmX + " + ex + " + M + " Nx" + i + " >= 0;\n";
    model += "dx" + i + " - " + elmX + " + ex - " + M + " Nx" + i + " <= 0;\n";
    model += "// Distancia en Y\n";
    model += "dy" + i + " - ey + " + elmY + " - " + M + " Ny" + i + " >= -" + M
            + ";\n";
    model += "dy" + i + " - ey + " + elmY + " + " + M + " Ny" + i + " <= " + M
            + ";\n";
    model += "dy" + i + " - " + elmY + " + ey + " + M + " Ny" + i + " >= 0;\n";
    model += "dy" + i + " - " + elmY + " + ey - " + M + " Ny" + i + " <= 0;\n";
    model += "// Distancia Total\n";
    model += "dx" + i + " + dy" + i + " = D" + i + ";\n\n";
    
    if (di == 0) {
//      ints+="bin Nx0, Ny0";
      if (!withBin)
        ints += "// ";
      
      ints += "bin Nx" + i + ", Ny" + i;
    }
    else {
      ints += ", Nx" + i + ", Ny" + i;
    }
    
  }
}

void Modeler::calculateConditions()
{
  int size = townsCoordinates.size();
  model += "// Calculo de los condicionales de la vereda más lejana\n";
  for (int di = 0; di < size; di++) {
    QString i = QString::number(di + 1);
    model += "L >= D" + i + ";\n";
  }
  ints += ";\n";
  obj += ";\n";
}

void Modeler::calculateDistancesAlternative(bool withBin)
{
  int size = townsCoordinates.size();
  for (int di = 0; di < size; di++) {
    QString i = QString::number(di + 1);
    QString elmX = QString::number(townsCoordinates[di].x());
    QString elmY = QString::number(townsCoordinates[di].y());
    
    model += "// Distancia de la escuela a " + i + "\n";
    model += "\n// Distancia en X\n";
    model += "dx" + i + " - ex + " + elmX + " - " + M + " Nx" + i + " >= -" + M
            + ";\n";
    model += "dx" + i + " - ex + " + elmX + " + " + M + " Nx" + i + " <= " + M
            + ";\n";
    model += "dx" + i + " - " + elmX + " + ex + " + M + " Nx" + i + " >= 0;\n";
    model += "dx" + i + " - " + elmX + " + ex - " + M + " Nx" + i + " <= 0;\n";
    model += "\n// Distancia en Y\n";
    model += "dy" + i + " - ey + " + elmY + " - " + M + " Ny" + i + " >= -" + M
            + ";\n";
    model += "dy" + i + " - ey + " + elmY + " + " + M + " Ny" + i + " <= " + M
            + ";\n";
    model += "dy" + i + " - " + elmY + " + ey + " + M + " Ny" + i + " >= 0;\n";
    model += "dy" + i + " - " + elmY + " + ey - " + M + " Ny" + i + " <= 0;\n";
    model += "\n// Distancia Total\n";
    model += "dx" + i + " + dy" + i + " = D" + i + ";\n\n";
    
    //bin+="Nx"+i+" <= 1;\n";
    //bin+="Ny"+i+" <= 1;\n";
    if (di == 0) {
      if (!withBin)
        ints += "// ";
      
      ints += "bin Nx1, Ny1";
    }
    else {
      ints += ", Nx" + i + ", Ny" + i;
    }
    
  }
}

void Modeler::calculateConditionsAlternative()
{
  model += "// Calculo de los condicionales de la vereda más lejana\n";
  QString sumRi = "";
  int size = townsCoordinates.size();
  
  for (int di = 0; di < size; di++) {
    QString i = QString::number(di + 1);
    for (int dj = 0; dj < size; dj++) {
      QString j = QString::number(dj + 1);
      if (di != dj) {
        model += "D" + i + " - D" + j + " - " + M + " r" + i + " >= -" + M
                + ";\n";
      }
    }
    if (di == 0) {
      sumRi += "r" + i;
      
    }
    else {
      sumRi += " + r" + i;
    }
    //bin+="r"+i+" <= 1;\n";
    ints += ", r" + i;
  }
  sumRi += " = 1;\n\n";
  model += "\n// Solo hay una mas lejana que las demas\n";
  model += sumRi;
  ints += ";\n";
  
  model += "// Actualizar en algun A, la distancia mas lejana\n";
  for (int di = 0; di < size; di++) {
    QString i = QString::number(di + 1);
    model += "A" + i + " - D" + i + " - " + M + " r" + i + " >= -" + M + ";\n";
    model += "A" + i + " - D" + i + " + " + M + " r" + i + " <= " + M + ";\n";
    model += "A" + i + " - " + M + " r" + i + " <= 0;\n";
    
    if (di == 0) {
      obj += " A" + i;
    }
    else {
      obj += " + A" + i;
    }
  }
  
  obj += ";\n";
}



//QString Modeler::writeModel(QString fileName)
//{
//  QFile file(fileName);
//  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//    QTextStream out(&file);
//    out << model;
//    return "The model has been generated in " + fileName;
//  }
//  else {
//    return "An error has ocurred writing the file";
//  }
//}

bool Modeler::writeModel(QString fileName)
{
  QFile file(fileName);
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    out << model;
    return true;
  }
  
  return false;
}

//**************************************************************
/*

Modeler::Modeler(const ParametersSet & parametersSetObject)
{
  regionSize = parametersSetObject.getRegionSize();
  nTowns = parametersSetObject.getNTowns();
  townsNumbers = parametersSetObject.getTownsNumbers();
  townsCoordinates = parametersSetObject.getTownsCoordinates();
  initialize();
}

void Modeler::initialize()
{
  obj = "// Funcion Objetivo\n";
  obj += "min:";
  model = "// Calculo de las Distancias entre la escuela y las veredas\n";
  //bin="// Restricciones Binarias\n";
  ints = "// Restricciones Binarias\n";
  bigM = static_cast<double> (regionSize * 2);
  model = "// Puntos\n// " + printPoints() + "\n\n" + model;
  M = QString::number(bigM);
}

void Modeler::generateModel(bool withBin)
{
  model2D(withBin);
  //return model;
}

QString Modeler::qpointToString(const QPointF & p)
{
  QString x = QString::number(p.x());
  QString y = QString::number(p.y());
  return "(" + x + ", " + y + ")";
}

QString Modeler::printPoints()
{
  QString out = "{" + qpointToString(townsCoordinates[0]);
  for (int i = 1; i < townsCoordinates.size(); i++) {
    out += " , " + qpointToString(townsCoordinates[i]);
  }
  out += "}";
  return out;
}

void Modeler::model2D(bool withBin)
{
//  if (withBin) {
    calculateDistances(withBin);
    model += "\n";
    calculateConditions();
    model = obj + "\n" + model + "\n" + ints;
//  }
//  else {
//    calculateDistances();
//    model += "\n";
//    calculateConditions();
//    model = obj + "\n" + model + "\n" + ints;
//  }
}

void Modeler::calculateDistances(bool withBin)
{
  int size = townsCoordinates.size();
  for (int di = 0; di < size; di++) {
    QString i = QString::number(di + 1);
    QString elmX = QString::number(townsCoordinates[di].x());
    QString elmY = QString::number(townsCoordinates[di].y());
    
    model += "// Distancia de la escuela a " + i + "\n";
    model += "\n// Distancia en X\n";
    model += "dx" + i + " - ex + " + elmX + " - " + M + " Nx" + i + " >= -" + M
            + ";\n";
    model += "dx" + i + " - ex + " + elmX + " + " + M + " Nx" + i + " <= " + M
            + ";\n";
    model += "dx" + i + " - " + elmX + " + ex + " + M + " Nx" + i + " >= 0;\n";
    model += "dx" + i + " - " + elmX + " + ex - " + M + " Nx" + i + " <= 0;\n";
    model += "\n// Distancia en Y\n";
    model += "dy" + i + " - ey + " + elmY + " - " + M + " Ny" + i + " >= -" + M
            + ";\n";
    model += "dy" + i + " - ey + " + elmY + " + " + M + " Ny" + i + " <= " + M
            + ";\n";
    model += "dy" + i + " - " + elmY + " + ey + " + M + " Ny" + i + " >= 0;\n";
    model += "dy" + i + " - " + elmY + " + ey - " + M + " Ny" + i + " <= 0;\n";
    model += "\n// Distancia Total\n";
    model += "dx" + i + " + dy" + i + " = D" + i + ";\n\n";
    
    //bin+="Nx"+i+" <= 1;\n";
    //bin+="Ny"+i+" <= 1;\n";
    if (di == 0) {
      if (!withBin)
        ints += "// ";
      
      ints += "bin Nx1, Ny1";
    }
    else {
      ints += ", Nx" + i + ", Ny" + i;
    }
    
  }
}

void Modeler::calculateConditions()
{
  model += "// Calculo de los condicionales de la vereda más lejana\n";
  QString sumRi = "";
  int size = townsCoordinates.size();
  
  for (int di = 0; di < size; di++) {
    QString i = QString::number(di + 1);
    for (int dj = 0; dj < size; dj++) {
      QString j = QString::number(dj + 1);
      if (di != dj) {
        model += "D" + i + " - D" + j + " - " + M + " r" + i + " >= -" + M
                + ";\n";
      }
    }
    if (di == 0) {
      sumRi += "r" + i;
      
    }
    else {
      sumRi += " + r" + i;
    }
    //bin+="r"+i+" <= 1;\n";
    ints += ", r" + i;
  }
  sumRi += " = 1;\n\n";
  model += "\n// Solo hay una mas lejana que las demas\n";
  model += sumRi;
  ints += ";\n";
  
  model += "// Actualizar en algun A, la distancia mas lejana\n";
  for (int di = 0; di < size; di++) {
    QString i = QString::number(di + 1);
    model += "A" + i + " - D" + i + " - " + M + " r" + i + " >= -" + M + ";\n";
    model += "A" + i + " - D" + i + " + " + M + " r" + i + " <= " + M + ";\n";
    model += "A" + i + " - " + M + " r" + i + " <= 0;\n";
    
    if (di == 0) {
      obj += " A" + i;
    }
    else {
      obj += " + A" + i;
    }
  }
  
  obj += ";\n";
}


QString Modeler::writeModel(QString fileName)
{
  QFile file(fileName);
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    out << model;
    return "The model has been generated in " + fileName;
  }
  else {
    return "An error has ocurred writing the file";
  }
}


bool Modeler::writeModel(QString fileName)
{
  QFile file(fileName);
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    out << model;
    return true;
  }
  
  return false;
}
*/
