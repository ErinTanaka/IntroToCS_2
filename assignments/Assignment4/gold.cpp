/**********************************
 *Program Filename: gold.cpp
 *Author: Erin Tanaka
 *Date: May 17, 2016
 *Description: Implementation for gold
 * *******************************/
#include "gold.h"
/*********************************
 *Function: gold (constructor)
 *Description: default constructor
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: ojbect has been made
 * ******************************/
gold::gold(): event(){}
/*********************************
 *Function: message
 *Description: prints percept
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: percept printed to screen
 * ******************************/
void gold::message(){
   cout << "You see a glimmer nearby." << endl;
}
/********************************
 *Function: occur
 *Description: returns int
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: int 1 returned
 * *****************************/
int gold::occurs(){
   return 1;
}
