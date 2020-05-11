/**********************************************************
 * Program Filename: driver.cpp
 * Author: Erin Tanaka
 * Date: May 18, 2016
 * Description: driver for hunt the wumpus
 * *******************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include "event.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include "room.h"
#include "game.h"
using namespace std;

int main(int argc, char * argv[]){
   srand (time(NULL));   
   bool arg=false;
   int size;
   while (arg==false){
      if(atoi(argv[1])>3){
         size=atoi(argv[1]);
	 arg=true;
      }
      else {
         cout << "Please enter a size 4 or higher: ";
	 cin >> argv[1];
      }
   
   }
   game hunt_the_wumpus(4);
   hunt_the_wumpus.play_game();

  
   return 0;
}
