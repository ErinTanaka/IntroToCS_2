/****************************************
 *Program: animal.h
 *Author: Erin Tanaka
 *Date: 5/6/16
 *Description: animal class
 ***************************************/
  
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <cstdlib>
using namespace std;
class animal{
   protected:
      int age;
      int cost;
      int food;
      int payout;
      int baby;
   public:
      animal(int, int, int, int, int);
      void age_up();
      int get_age();
      int get_cost();
      int get_food();
      int get_payout();
      int get_baby();
      void set_age(int);
};
#endif
