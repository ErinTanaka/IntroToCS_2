/*********************************************
 * Program Filename: event.h
 * Author: Erin Tanaka
 * Date: May 22, 2016
 * Description: event class
 * ******************************************/
#ifndef ROOM_H
#define ROOM_H
#include "event.h"

class room{
   private:
      bool has_event;
      event* e;
   public:
      room();// default constructor
      void set_bool(bool); //mutator
      void set_event(event*); //mutator
      bool get_bool(); //accessor
      event * get_event(); //accessor

      ~room();//destructor
};

#endif
