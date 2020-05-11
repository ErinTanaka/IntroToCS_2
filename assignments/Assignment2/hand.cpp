#include "hand.h"
/***********************************************
 *Function: hand
 *Description: default constructor sets cards to null and num cards to 0
 *Parameters: none
 *Preconditions: hand initialized
 *Postconditions: cards set to null and number of cards set to 0
 **********************************************/
hand::hand(){ 
   cards=NULL;
   num_cards=0;
}

/***********************************************
 *Function: set_card
 *Description: sets card at given position in hand to card passed in
 *Parameters: position in hand to set, card to be set to
 *Preconditions: hand contains cards
 *Postconditions: card at position  is set to given card
 **********************************************/
void hand::set_card(const int pos, const card c){ 
   cards[pos]=c;
}
/***********************************************
 *Function: set_num_cards
 *Description: sets number of cards
 *Parameters: number of cards to be set
 *Preconditions: hand initiaized
 *Postconditions: num_cards set to value passed in 
 **********************************************/
void hand::set_num_cards(const int c){
   num_cards=c;
}
/***********************************************
 *Function: get_cards
 *Description: retuns to 1t element of card array
 *Parameters: none
 *Preconditions: hand initialized cards exist
 *Postconditions: pointer to array of cards returned
 **********************************************/
card* hand::get_cards() const{
   return cards;
}
/***********************************************
 *Function: creae_cards 
 *Description: creates array of num_c cards 
 *Parameters: int number of cards to be made
 *Preconditions: hand initialized
 *Postconditions: card array of lenght num_c atored in cards
 **********************************************/
void hand::create_cards(const int num_c){
   delete [] cards; //delete old cards
   num_cards=num_c; //set num_cards
   cards=new card[num_c]; //allocate memory for new cards
}
/***********************************************
 *Function: get_num_cards
 *Description: retuns number of card in hand
 *Parameters: none
 *Preconditions: hand initialized
 *Postconditions: number of cards returned
 **********************************************/
int hand::get_num_cards() const 
{
   return num_cards;
}
/***********************************************
 *Function: hand copy constructor
 *Description: makes a dupicate hand of the one passed in
 *Parameters: hand to be copied
 *Preconditions: hand exists to be copied
 *Postconditions: duplicate hand is made
 **********************************************/
hand::hand(const hand & old){ 
   num_cards=old.get_num_cards(); //copy nmber of cards
   cards=new card[num_cards]; //allocate memory
   for (int i=0; i<num_cards; i++){ //setting cards
      cards[i]=old.cards[i];
   }
}
/***********************************************
 *Function: hand destructor
 *Description: deletes card array
 *Parameters: none
 *Preconditions: hand is initialized
 *Postconditions: card array is deleted
 **********************************************/
hand::~hand(){
   delete [] cards; 
}
/***********************************************
 *Function: hand operator overload 
 *Description: copies all elements of one hand to another
 *Parameters: hand to get elements/members from
 *Preconditions: two hands have been initialized
 *Postconditions: elements in second hand are the same as the elements in the first 
 **********************************************/
void hand::operator=(const hand & old){  
   delete [] cards; //delete any old cards
   cards = new card[old.num_cards]; //allocate new memory
   num_cards= old.num_cards; //set num cards
   for (int i=0; i<num_cards; i++){ //setting cards
      cards[i]=old.cards[i];
   }
}

