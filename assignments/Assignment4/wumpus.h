/*********************************
 *Program Filename: wumpus.h
 *Author: Erin Tanaka
 *Date: May 18, 2016
 *Description: class wumpus
 * ******************************/
#ifndef WUMPUS_H
#define WUMPUS_H
#include "event.h"
#include <iostream>
class wumpus : public event{
   public:
      wumpus(); //default constructor
     virtual void message(); //prints message
     virtual int occurs(); //event occurs
};
#endif
