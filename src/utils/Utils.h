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
#include <cmath>

// PROJECT INCLUDES


namespace utils 
{
  inline double round(double number) {
    return floor(number + 0.5);
  }
   
  inline float round(float number) {
    return floor(number + 0.5);
  }
  
  inline double decimalPart(double number){
    double integer = floor(number);
    double decimal = number - integer;
    return decimal;
  }
  
  inline double decimalPart(float number){
    float integer = floor(number);
    float decimal = number - integer;
    return decimal;
  }
  
}
#endif /* UTILS_H_ */
