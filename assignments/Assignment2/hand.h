#ifndef HAND_H
#define HAND_H
#include "card.h"
//#ifndef DECK_H
//#define DECK_H
#include "deck.h"

class hand{
   private:
      card *cards;
      int num_cards;
   public:
      hand(); //default constructor
      //hand(int);
      void set_card(const int, const card); // set one card in hand
      card* get_cards() const; //return pointer to 1st card in hand
      void create_cards(const int); //set number of cards and make array
      int get_num_cards() const; //return number of cards in hand
      void set_num_cards(const int);
      //Big Three
      hand(const hand &); //copy constructor
      ~hand(); //destructor
      void operator=(const hand &); //assignment operator overload      
      
};
#endif
