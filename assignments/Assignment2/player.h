#ifndef PLAYER_H
#define PLAYER_H
#include "hand.h" 
class player{
   private:
      hand p_hand;
      int playing_total;
      int card_total;
      int bet;
   public:
      player();
      hand * get_hand();
      int get_playing_total();
      int get_card_total();
      int get_bet();

      void set_playing_total(int);
      void set_card_total(int);
      void set_bet(int);
      
      void calculate_card_total();
      void add_card(const card);
      bool check_bust();
      void make_bet();
      void print_hand();
};
#endif
