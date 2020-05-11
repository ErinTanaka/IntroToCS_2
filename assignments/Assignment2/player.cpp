#include "player.h"

/***********************************************
 *Function: player default constructor
 *Description: sets totals and bet to 0 
 *Parameters: none
 *Preconditions: player is initialized
 *Postconditions: player's totals get set to zero'
 **********************************************/
player::player(){
   playing_total=0;
   card_total=0;
   bet=0;
} 
/***********************************************
 *Function: get_hand
 *Description: address of hand is returned
 *Parameters: none
 *Preconditions: player is initialized
 *Postconditions: address of hand returned 
 **********************************************/
hand* player::get_hand(){
   return &p_hand;
}
/***********************************************
 *Function: get_playing_total
 *Description: playing total returned
 *Parameters: none
 *Preconditions: player is initialized
 *Postconditions: int playing total is returned
 **********************************************/
int player::get_playing_total(){
   return playing_total;
}
/***********************************************
 *Function: get_card_total
 *Description: returns int 
 *Parameters: none
 *Preconditions: player initialized
 *Postconditions: int card total returned
 **********************************************/
int player::get_card_total(){
   return card_total;
}
/***********************************************
 *Function: get_bet
 *Description: assessor returns int
 *Parameters: none
 *Preconditions: player initialized
 *Postconditions: int bet is returned
 **********************************************/
int player::get_bet(){
   return bet;
}
/***********************************************
 *Function: set_playing_total
 *Description: mutator sets playing total
 *Parameters: int new total
 *Preconditions: player initialized
 *Postconditions: playing total is set to n_total
 **********************************************/
void player::set_playing_total(int n_total){
   playing_total=n_total;
}
/***********************************************
 *Function: set_card_total
 *Description: mutator sets card total to given parameter
 *Parameters: int new total
 *Preconditions: player initialized
 *Postconditions: card total updated with new total
 **********************************************/
void player::set_card_total(int n_total){
   card_total=n_total;
}
/***********************************************
 *Function: set_bet
 *Description: mutator sets bet to new int
 *Parameters: int bet
 *Preconditions: none
 *Postconditions: bet is set to new int
 **********************************************/
void player::set_bet(int n_bet){
   bet=n_bet;
}
      
/***********************************************
 *Function: calculate_card_total
 *Description: calculates card value totals if card is ace asks if it should be a 1 or 11
 *Parameters: none
 *Preconditions: hand has cards in it
 *Postconditions: card total is updated with new number
 **********************************************/
void player::calculate_card_total(){
   int choice;
   int temptotal=0;
   for (int i=0; i<p_hand.get_num_cards(); i++){ //iterate though cards in hand
      if (p_hand.get_cards()[i].value==1){ //card is ace
         cout << "Ace high/11 (0) or low/1 (1)? ";
	 cin >> choice;
	 if (choice==0){ //ace is high
	    temptotal=temptotal+11;
	 }
	 else { //ace is low
	    temptotal=temptotal+1;
	 }
      }
      else if(p_hand.get_cards()[i].value>=10){ //face card
         temptotal=temptotal+10;
      }
      else{ //2-10
         temptotal=temptotal+p_hand.get_cards()[i].value;
      }
   }
   card_total=temptotal;
}
      
/***********************************************
 *Function: check_bust
 *Description: returns bool depending on if player's cards are over 21
 *Parameters: none
 *Preconditions: card total has been calclated
 *Postconditions: false returned if bust true returned if cards are less than or equal to 21
 **********************************************/
bool player::check_bust(){
   if (card_total>21){ 
      cout << "Bust! End of turn!"<< endl;
      return false;
   }
   else return true;
}

/***********************************************
 *Function: add_card
 *Description: adds a card to players hand
 *Parameters: const card
 *Preconditions: hand initialized
 *Postconditions: new card added to hand
 **********************************************/
void player::add_card(const card c){
   card* temp; //temp to make new hand
   temp=new card[p_hand.get_num_cards()+1]; // allocating space for current number of cards plus 1
   for (int i=0; i<p_hand.get_num_cards(); i++){ //copying old cards
      temp[i]=p_hand.get_cards()[i];
   }
   temp[p_hand.get_num_cards()]=c; //addign new card
   p_hand.create_cards(p_hand.get_num_cards()+1); //making new array
   for (int i=0; i< p_hand.get_num_cards(); i++){ //copying cards
      p_hand.set_card(i,temp[i]);
   }
   delete [] temp; //deleting temp
}
/***********************************************
 *Function: print_hand 
 *Description: prints cards in player's hand
 *Parameters: none
 *Preconditions: player has cards in their hand
 *Postconditions: value and suit of each card in player's hand is printed to screen
 **********************************************/
void player::print_hand(){
   for (int i=0; i< p_hand.get_num_cards(); i++){ //cycle through cards
      if (p_hand.get_cards()[i].value<=10){ // not a face card
         if (p_hand.get_cards()[i].value==1){ //ace
            cout << "Ace" << " " << p_hand.get_cards()[i].suit << endl;
	 }
	 else{ //2-10
	    cout << p_hand.get_cards()[i].value << " " << p_hand.get_cards()[i].suit << endl;
         }
      }
      else{ //face card
         if (p_hand.get_cards()[i].value==11){ //jack
            cout << "Jack" << " " << p_hand.get_cards()[i].suit << endl;
	    
	 }
         else if (p_hand.get_cards()[i].value==12){ //queen
            cout << "Queen" << " " << p_hand.get_cards()[i].suit << endl;
	 }
	 else{  //king
	    cout << "King" << " " << p_hand.get_cards()[i].suit << endl;
	 }
      }
         
   }
}
