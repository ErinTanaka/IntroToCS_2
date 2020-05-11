#include "dealer.h"
/***********************************
 *Function: dealer
 *Description: default constructor for dealer class
 *Parameters:none
 *Preconditions:none
 *Postconditions:dealer has a null hand and a card total of 0
 **********************************/
dealer::dealer(){
   d_hand;
   card_total=0;
}
      
/***********************************
 *Function: get_hand
 *Description: accessor returns address of dealer's hand'
 *Parameters: none
 *Preconditions: dealer has been made and hand has been made
 *Postconditions: address of dealer's hand is returned'
 **********************************/
hand* dealer:: get_hand(){
   return & d_hand;
}
      
/***********************************
 *Function: get_card_total
 *Description:accessor returns card total
 *Parameters: none
 *Preconditions: dealer has been made
 *Postconditions:int card_total is returned
 **********************************/
int dealer::get_card_total(){
   return card_total;
}
      
/***********************************
 *Function:set_card_total
 *Description:mutator sets card total
 *Parameters: int what to total is geting set to
 *Preconditions: dealer has been made
 *Postconditions: card_total is updated with new number
 **********************************/
void dealer::set_card_total(int c){
   card_total=c;
}

/***********************************
 *Function: calculate_card_total
 *Description: adds up point values of dealer's hand
 *Parameters: none
 *Preconditions: dealer has been made and dealer's hand has cards in it
 *Postconditions: card total is updated with newly calculated one
 **********************************/
void dealer::calculate_card_total(){      
   int choice;
   int temptotal=0;
   for (int i=0; i<d_hand.get_num_cards(); i++){  //cycle through cards in dealer's hand
      if (d_hand.get_cards()[i].value==1){ //card is an ace
         cout << "Ace high/11 (0) or low/1 (1)? ";
	 cin >> choice;
	 if (choice==0){
	    temptotal=temptotal+11;
	 }
	 else {
	    temptotal=temptotal+1;
	 }
      }
      else if(d_hand.get_cards()[i].value>=10){  //card is a face card
         temptotal=temptotal+10;
      }
      else{ //card is 2-10
         temptotal=temptotal+d_hand.get_cards()[i].value;
      }
   }
   card_total=temptotal; //updates card total

}
      
/***********************************
 *Function: hit_or_stay
 *Description: returns t/f depending on if dealers cards are >=17
 *Parameters:none
 *Preconditions:dealer has been made and has cards in its hand
 *Postconditions: t returned of good to hit f returned to stay
 **********************************/
bool dealer::hit_or_stay(){
   if(card_total>=17) return false;
   else return true;
}

/***********************************
 *Function:add_card
 *Description: adds one cardto hand and updates total
 *Parameters: card from the deck
 *Preconditions: dealer has been made and has atleast 1 card in hand
 *Postconditions: dealer's hand has one new card
 **********************************/
void dealer::add_card(const card c){
   card* temp;
   temp=new card[d_hand.get_num_cards()+1];  //temporary card array to get old cards and new one into one place
   for (int i=0; i<d_hand.get_num_cards(); i++){  //getting old hand
      temp[i]=d_hand.get_cards()[i];
   }
   temp[d_hand.get_num_cards()]=c;  //adding new card
   d_hand.create_cards(d_hand.get_num_cards()+1);
   for (int i=0; i< d_hand.get_num_cards(); i++){
      d_hand.set_card(i,temp[i]);
   }
   delete [] temp;
}

/*********************************
 *Function: print_card_one 
 *Description: prints first card in dealers hand
 *Parameters: none
 *Preconditons: dealer has been mad and has at least one card
 *Postconditions: value and sit of one card in dealer's hand is printed to screen
 * ******************************/
void dealer::print_card_one(){
   if(d_hand.get_cards()[0].value>10){
      if(d_hand.get_cards()[0].value==11){
	 cout << "Jack " << d_hand.get_cards()[0].suit << endl;
      }
      else if(d_hand.get_cards()[0].value==12){
	 cout << "Queen " << d_hand.get_cards()[0].suit << endl;
      }
      else {
	 cout << "King " << d_hand.get_cards()[0].suit << endl;
      }
   }
   else{
      cout << d_hand.get_cards()[0].value << " " << d_hand.get_cards()[0].suit << endl;
   }
}
/*********************************
 *Function: print_all_cards 
 *Description: prints all cards in the dealers hand
 *Parameters: none
 *Preconditons: dealer has been made and has at least one card in its hand
 *Postconditions: suit and value of eack card i dealer's hand printed to screen
 * ******************************/
void dealer::print_all_cards(){
   for (int i=0; i<d_hand.get_num_cards(); i++){
      if(d_hand.get_cards()[i].value>10){
         if(d_hand.get_cards()[i].value==11){
	    cout << "Jack " << d_hand.get_cards()[i].suit << endl;
         }
         else if(d_hand.get_cards()[i].value==12){
	    cout << "Queen " << d_hand.get_cards()[i].suit << endl;
         }
         else {
	    cout << "King " << d_hand.get_cards()[i].suit << endl;
         }
      }
      else if (d_hand.get_cards()[i].value==1){
	    cout << "Ace " << d_hand.get_cards()[i].suit << endl;
      }
      else{
         cout << d_hand.get_cards()[i].value << " " << d_hand.get_cards()[i].suit << endl;
      }
   }
   cout << endl;
}
