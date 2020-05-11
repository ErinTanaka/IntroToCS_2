/*****************************************
 *Program:driver.cpp
 *Author:Erin Tanaka
 *Date:5/6/16
 *Description: driver for zoo tycoon
 * *************************************/
#include "zoo.h"
#include <ctime>

int main(){
  srand (time(NULL));
   
   int animals;
   cout << "WELCOME TO ZOO TYCOON" << endl;
   cout << "Would you like to start you zoo with 1 or 2 animals?" << endl;
   cout << "Your starting bank total is $100000" << endl;
   cout << "One of each costs $16000 (1) Two of each costs $32000(2): ";
   cin >> animals; 
   zoo play(animals);
   play.day();
   cout << play.bonus << endl;
   return 0;
}
