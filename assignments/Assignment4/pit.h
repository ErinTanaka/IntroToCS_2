/*********************************
 *Program Filename: pit.h
 *Author: Erin Tanaka
 *Date: May 17, 2016
 *Description: class pit
 * ******************************/
#ifndef PIT_H
#define PIT_H
#include "event.h"
#include <iostream>
class pit : public event{
   public:
      pit(); //default constructor
      void message(); //prints message
      int occurs(); //event occurs
};
#endif
