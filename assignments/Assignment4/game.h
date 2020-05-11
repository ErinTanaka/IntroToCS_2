/**************************************
 * Program Filename: game.h
 * Author: Erin Tanaka
 * Date: May 18, 2016
 * Description: game class
 * **********************************/
#ifndef GAME_H
#define GAME_H
#include "event.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include "room.h"
#include <vector>
class game{
   private:
      int player_row;
      int player_col;
      
      int start_row;
      int start_col;
      
      int wstart_row;
      int wstart_col;

      int arrows;
      int size; 
      
      bool have_gold;
      bool player_dead;
      bool wumpus_dead;

      vector< vector<room> > grid;
 
      bats * b1;
      bats * b2;
      gold * g;
      pit * p1;
      pit * p2;
      wumpus * w;
 
   public:
      game(int); //non-default constructor

      //setup
      void make_grid(int);
      void set_bats(); 
      void set_pit(); 
      void set_gold(); 
      void set_wumpus(); 
      void set_player_start();
      void print_cheater_grid();
      
      //gameplay
      void play_game();
      void play_game_alive();
      void play_game_dead();
      
      //move shoot
      void move_player(); 
      void player_shoot(); 
      
      //shoot
      void shoot_north(); 
      void shoot_south(); 
      void shoot_east(); 
      void shoot_west(); 
      void scare_wumpus(); 

      //events
      void player_event(); 
      void game_gold(); 
      void game_pit(); 
      void game_bats(); 
      void game_wumpus();
      
      void print_messages(); 

      //end game
      void prompt_new_game_death(); 
      void prompt_new_game_win(); 
      void reset_game(); 
      void reset_board(); 
      void make_new_grid(int, int);
};
#endif
