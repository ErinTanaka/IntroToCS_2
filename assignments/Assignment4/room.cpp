/*********************************************
 * Program Filename: room.cpp
 * Author: Erin Tanaka
 * Date: May 22, 2016
 * Description: implementation for room class
 * ****************************************/
#include "room.h"
/******************************************
 * Function: room
 * Description: default constructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: object made pointer set to null bool set to false
 *****************************************/
room::room(){
   e=NULL;
   has_event=false;
}
/******************************************
 * Function: set_bool
 * Description: sets bool to passed parameter
 * Parameters: bool
 * Pre-Conditions: none
 * Post-Conditions: has_event set to parameter
 *****************************************/
void room::set_bool(bool b){
   has_event=b;
}
/******************************************
 * Function: set_event
 * Description: sets pointer
 * Parameters: pointer to event
 * Pre-Conditions: none
 * Post-Conditions: e set to pointer
 *****************************************/
void room::set_event(event* n){
   e=n;
}
/******************************************
 * Function: get_bool
 * Description: returns has event bool
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: bool returned
 *****************************************/
bool room::get_bool(){
   return has_event;
}
/******************************************
 * Function: get_event
 * Description: returns pointer to event
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: pointer to event returned
 *****************************************/
event * room::get_event(){
   return e;
}
/******************************************
 * Function: ~room
 * Description: deletes event pointer
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: destructor for room
 *****************************************/
room::~room(){
   delete [] e;
}

