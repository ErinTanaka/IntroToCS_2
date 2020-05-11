#ifndef DECK_H
#define DECK_H
#include "card.h"

class deck{
   private:
      card cards[52];
      int num_cards;
      int location;
   public:
      deck ();     
      
      card get_card(int);
      int get_location();
      
      void set_cards_num();
      void set_location(int);
      
      void shuffle_deck();
      void populate_deck();
};
#endif
