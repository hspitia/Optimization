/**
 * @file FileParser.h
 * @date 23/11/2009
 * @author He-.ctor Fabio Espitia Navarro <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y 
 * Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief 
 */

/* 
 *         File:  FileParser.h
 *   Created on:  23/11/2009
 *       Author:  He-.ctor Fabio Espitia Navarro
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y 
 *                COMPUTACION 
 *      Project:  Optimization
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  
 */

#ifndef FILEPARSER_H_
#define FILEPARSER_H_

#include <QtCore/QList>
#include <QtCore/QPointF>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QString>
#include <QtCore/QStringList>

// Std
#include <iostream>

using namespace std;

#include <parser/ParametersSet.h>


/**
 * 
 */
class FileParser
{
  public:
    FileParser();
    virtual ~FileParser();
    
    int getNSchools();
    QList<QPointF> getSchoolCoordinates();
    QList<int> getSchoolsNumbers();
    ParametersSet * getParametersSet();
    
    bool parseFile(const QString & filePath);
    
  private:
    ParametersSet * parametersSet;
    
};

#endif /* FILEPARSER_H_ */
