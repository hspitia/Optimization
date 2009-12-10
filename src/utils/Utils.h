/**
 * @file utils.h
 * @date 14/09/2009
 * @author He-.ctor Fabio Espitia Navarro <br>
 * Universidad del Valle - Escuela de Ingenier&iacute;a de Sistemas y Computaci&oacute;n.<br>
 * Santiago de Cali - Colombia
 * @brief Utilidades varias.
 */

/* 
 *         File:  utils.h
 *   Created on:  14/09/2009
 *       Author:  He-.ctor Fabio Espitia Navarro
 *  Institution:  UNIVERSIDAD DEL VALLE - ESCUELA DE INGENIERIA DE SISTEMAS Y COMPUTACION 
 *      Project:  Optimization
 *      License:  GNU GPL. See more details in LICENSE file
 *  Description:  Utilidades varias.
 */


#ifndef UTILS_H_
#define UTILS_H_

// SYSTEM INCLUDES
#include <QtCore>
#include <cmath>
#include <iostream>

// PROJECT INCLUDES


namespace utils 
{
  inline double round(double number) {
    return floor(number + 0.5);
  }
  
  inline float round(float number) {
    return floor(number + 0.5);
  }
  
  inline long double decimalPart(long double number){
    long double integer = floor(number);
    long double decimal = number - integer;
    
    std::cout << "\nnumber: " << number 
              << " integer: " << integer
              << " decimal: " << decimal << endl;
    
    return decimal;
  }
  
  inline bool isInteger(long double number){
    long double decimal =  decimalPart(number);
    if (decimal != 0.0) {
      long double diference = 1 - decimal;
      long double tolerance = 0.000000001;
      
      if (diference <= tolerance)
        return true;
        
      return false;
    }
    
    return true;
  }
}
#endif /* UTILS_H_ */
