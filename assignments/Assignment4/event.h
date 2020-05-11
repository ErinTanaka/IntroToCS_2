/*******************************
 *Program Filename: event.h
 *Author: Erin Tanaka
 *Date: May 17, 2016
 *Description: event class
 * **************************/
#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <cstdlib>
using namespace std;
class event{
   public:
      event(); //default constructor
      virtual void message()=0; //prints percept pure virtual
      virtual int occurs()=0; //will return unique int per different type of event
};
#endif
