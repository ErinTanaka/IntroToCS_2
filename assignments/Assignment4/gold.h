/**********************************
 *Program Filename: gold.h
 *Author: Erin Tanaka
 *Date: May 17, 2016
 *Description: gold class
 * *******************************/
#ifndef GOLD_H
#define GOLD_H
#include "event.h"
#include <iostream>
class gold:public event{
   public:
      gold(); //default constructor
      void message(); //print message
      int occurs(); //event occurs
};
#endif
