/*****************************************
 *Program: tiger.cpp
 *Author: Erin Tanaka
 *Date: 5/6/16
 *Description: Implementation for tiger class
 * **************************************/
#include "tiger.h"

/*******************************************
 * Function: penguin
 * Description: constructor for penguin
 * Parameters: none
 * Pre-Conditions: none
 * Post_conditions: penguin made and animal constructed with given vals
 * ****************************************/
tiger::tiger() : animal(3,10000, 125,1000,1){}
/*******************************************
 * Function: bonus payout
 * Description: returns bonus payout
 * Parameters: int bonus
 * Pre-Conditions: bonus generated
 * Post_conditions: payout plus bonus is returned
 * ****************************************/
int tiger::bonus_payout(int n){
   if (age<=3){
      return payout*2+n;
   }
   return payout+n;
}
