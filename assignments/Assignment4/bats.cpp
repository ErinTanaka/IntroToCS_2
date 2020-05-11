/**************************************
 * Program Filename: bats.cpp
 * Author: Erin Tanaka
 * Date: May 18, 2016
 * Description: Implementation of bats class
 * ***********************************/
#include "bats.h"
/**************************************
 *Function: bats
 * Description: default constructor
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: object made
 * ***********************************/
bats::bats():event(){}
/*********************************
 *Function: message
 *Description: prints percept
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: percept printed to screen
 * ******************************/
void bats::message(){
   cout << "You hear wings flapping." << endl;
}
/********************************
 *Function: occur
 *Description: returns int
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: int 1 returned
 * *****************************/
int bats::occurs(){
   return 3;
}
