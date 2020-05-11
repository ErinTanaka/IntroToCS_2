/**********************************
 *Program Filename: wumpus.cpp
 *Author: Erin Tanaka
 *Date: May 18, 2016
 *Description: Implementation for wumpus class
 * *******************************/
#include "wumpus.h"
/*********************************
 *Function: wumpus default constructor
 *Description: makes object
 *Parameters: none
 *Pre-conditions: none
 *Post-Conditions: object made
 ********************************/
wumpus::wumpus():event(){}
/********************************
 *Function: message
 *Description: prints location for testing purposes and pecept
 *Parameters: none
 *Pre-conditions: none
 *Post-conditions: percept printed to screen
 * *****************************/
void wumpus::message(){
   cout << "You smell a terrible stench." << endl; 
}
/*******************************
 *Function: occur
 *Description: returns int to determin which event happens
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: 2 is returned
 * ***************************/
int wumpus::occurs(){
   return 4;
}
