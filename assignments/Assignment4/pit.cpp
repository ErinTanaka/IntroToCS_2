/**********************************
 *Program Filename: pit.cpp
 *Author: Erin Tanaka
 *Date: May 17, 2016
 *Description: Implementation for pit class
 * *******************************/
#include "pit.h"
/*********************************
 *Function: pit default constructor
 *Description: makes object
 *Parameters: none
 *Pre-conditions: none
 *Post-Conditions: object made
 ********************************/
pit::pit():event(){}
/********************************
 *Function: message
 *Description: prints location for testing purposes and pecept
 *Parameters: none
 *Pre-conditions: none
 *Post-conditions: percept printed to screen
 * *****************************/
void pit::message(){
   cout << "You feel a breeze." << endl; 
}
/*******************************
 *Function: occur
 *Description: returns int to determin which event happens
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: 2 is returned
 * ***************************/
int pit::occurs(){
   return 2;
}
