/************************************
 * Program Filename: bats.h
 * Author: Erin Tanaka
 * Date: May 18, 2016
 * Description: bat class
 * ********************************/
#ifndef BATS_H
#define BATS_H
#include "event.h"
#include <iostream>
class bats:public event{
   public:
      bats(); //default constructor
      void message(); //print message
      int occurs(); //event occurs
};
#endif
