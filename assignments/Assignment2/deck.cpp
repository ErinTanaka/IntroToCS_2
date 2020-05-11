#include "deck.h"
/*************************************
 *Function: deck
 *Description: default constructor
 *Parameters: none
 *Preconditions: none
 *Postconditions: deck is made and has cards
 * **********************************/
deck::deck (){
   num_cards=52;
   location=0;
   set_cards_num();
}
/*********************************
 *Function: set_location 
 *Description: mutator sets location
 *Parameters: integer for new location
 *Preconditons: deck has been made
 *Postconditions: location set to new number passed into function
 * ******************************/
void deck:: set_location(int l){
   location=l;
}
/*********************************
 *Function: set_cards_num 
 *Description: gives ech card in deck value and suit
 *Parameters: none
 *Preconditons: deck has been made
 *Postconditions: each card has a value and suit
 * ******************************/
void deck::set_cards_num(){
   int i=0;
   while (i<52){ //cycle through each card in deck
      for (int j=1; j<5; j++){ //cycle through 4 suits
         for (int k=1; k<14; k++){ // cycle through values 1-13 for cards
	    if (j==1){
	       cards[i].value=k;
	       cards[i].suit="Heart";
	       i++;   
	    }
	    else if (j==2){
	       cards[i].value=k;
	       cards[i].suit="Diamond";
	       i++;   
	    }
	    else if (j==3){
	       cards[i].value=k;
	       cards[i].suit="Spade";
	       i++;   
	    }
	    else {
	       cards[i].value=k;
	       cards[i].suit="Club";
	       i++;   
	    }
	 }
      }      
   }

}
/*********************************
 *Function: get_location 
 *Description: returns int location
 *Parameters: none
 *Preconditons: deck has been made
 *Postconditions: interger is returned
 * ******************************/
int deck::get_location(){
   return location;
}
/*********************************
 *Function: get_card
 *Description: returns one card from deck
 *Parameters: integer of location in deck array to retrieve card from
 *Preconditons: deck has been made
 *Postconditions: cardfrom deck at location of given int is retuned
 * ******************************/
card deck::get_card(int i){
   return cards[i];
}
/*********************************
 *Function: shuffle_deck 
 *Description: shuffles cards in deck
 *Parameters: none
 *Preconditons: deck has been made
 *Postconditions: cards in deck are no longer in orde by suit and value
 * ******************************/
void deck::shuffle_deck(){
   //cout << "shuffling"<< endl;
   int x, y;
      card temp;
      for(int i=0; i<1000; i++){ //repeating swaps
	 
         x=rand() % 52; //generate 1st ramdom location
	 y=rand() % 52; //generate 2nd random location
	 temp=cards[x]; //swap cards in two generated locations
	 cards[x]=cards[y];
	 cards[y]=temp;
         
      }
   //cout << "deck shuffled"<< endl;   
}
/*********************************
 *Function: populate_deck
 *Description: reshuffles deck and resets location
 *Parameters: none
 *Preconditons: deck has been made
 *Postconditions: deck has been reshuffled and location reset
 * ******************************/
void deck::populate_deck(){
   //cout << "populating deck" << endl;
   location=0;
   shuffle_deck();
}

