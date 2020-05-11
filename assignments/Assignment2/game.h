#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "dealer.h"
#include "deck.h"

class game{
   private:
      player *players;
      dealer game_dealer;
      int num_players;
      deck cards;
   public:
      game();//default

      void set_num_players(int);
      void set_players(int);
      
      //Big three
      game(const game &);
      ~game();
      void operator=(const game &);

      void play_game();
      void start_game();
      void make_player_bets();
      void deal_cards();
      void player_hit_stay();
      void dealer_gameplay();
      void end_round();
      bool play_again();
};
#endif
