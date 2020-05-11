/******************************************
 *Program: animal.cpp
 *Author: Erin Tanaka
 *Date: 5/6/2016
 *Description: implementation for animal class
 * ****************************************/
#include "animal.h"
/******************************************
 *Function: animal (constructor)
 *Description: non default constructor
 *Parameters: integers for age cost food cost payout and number of babies
 *Pre-Conditions: none
 *Post-Conditions: animal object mad with members set to parameters
 * ***************************************/
animal::animal(int a, int c, int f, int p, int b){
   age=a;
   cost=c;
   food=f;
   payout=p;
   baby=b;
};
/******************************************
 *Function: age up
 *Description: increases age member by one
 *Parameters: none
 *Pre-Conditions none
 *Post-Conditions: age member increased by one
 * ***************************************/
void animal::age_up(){
   age++;
}
/******************************************
 *Function: get age
 *Description: return age
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: age returned
 * ***************************************/
int animal::get_age(){
   return age;
}
/******************************************
 *Function: get cost
 *Description: return cost
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: cost returned
 * ***************************************/
int animal::get_cost(){
   return cost;
}
/******************************************
 *Function: get food
 *Description: return fod cost
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: cost of food returned
 * ***************************************/
int animal::get_food(){
   return food;
}
/******************************************
 *Function: get payout
 *Description: return payout
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: payout returned
 * ***************************************/
int animal::get_payout(){
   return payout;
}
/******************************************
 *Function: get baby
 *Description: return number of babies
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: number of babies returned
 * ***************************************/
int animal::get_baby(){
   return baby;
}
/*****************************************
 *Function: set age
 *Description: sets ageto parameter passed in
 *Parameters: int age to be set
 *Pre-Conditions: none
 *Post-Conditions: age is updated to parameter
 * *************************************/
void animal::set_age(int n){
   age=n;
}
