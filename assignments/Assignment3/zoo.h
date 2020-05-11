/*********************************************
 *Program: zoo.h
 *Author: Erin Tanaka
 *Date: 5/6/16
 *Description: zoo class
 * *****************************************/
#include "penguin.h"
#include "polarbear.h"
#include "tiger.h"

class zoo{
   private:
      int bank;
      penguin* p_exhibit;
      polarbear* b_exhibit;
      tiger* t_exhibit;
      int penguins;
      int bears;
      int tigers;
      bool bonus;
      int bonus_val;
   public:
      zoo();
      zoo(int);
      void day();
      void feed_animals();
      void age_up_animals();
      void print_animals();
      void payout();
      void random_event();
      void sickness();
      void boom();
      void baby_born();
      bool check_tiger_age();
      bool check_bear_age();
      bool check_penguin_age();
      void buy_animal();
      void expand_bird(bool);
      void expand_bear(bool);
      void expand_tiger(bool);
      void shrink_bird(int);
      void shrink_bear(int);
      void shrink_tiger(int);

      ~zoo();

};
