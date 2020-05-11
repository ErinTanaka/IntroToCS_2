#ifndef DEALER_H
#define DEALER_H
#include "hand.h"
class dealer{
   private:
      hand d_hand;
      int card_total;
   public:
      dealer();

      hand * get_hand();
      int get_card_total();

      //~dealer();
      //void set_hand();
      void set_card_total(int);
      
      bool hit_or_stay();
      void add_card(const card);
      void calculate_card_total();
      void print_card_one();
      void print_all_cards();
};
#endif
