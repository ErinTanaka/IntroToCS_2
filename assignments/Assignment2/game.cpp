#include "game.h"
/*****************************************************
 *Function: game 
 *Description: default conctructor 
 *Parameters:none
 *Preconditions: none
 *Postconditions:game is made
 * *************************************************/
game::game(){
   players=NULL;
   num_players=1;
}     

/*****************************************************
 *Function: set_players 
 *Description: makes array of players
 *Parameters: number of players to be made
 *Preconditions: game had been made
 *Postconditions: players element gets array of player's of length p
 * *************************************************/
void game::set_players(int p){
   players=new player[p];
}     
/*****************************************************
 *Function: game
 *Description:  copy constructor
 *Parameters: old game
 *Preconditions: old game exists to be copied
 *Postconditions: new game is made with same contents as old game
 * *************************************************/
game::game(const game & old){
   cards=old.cards; //set deck
   game_dealer=old.game_dealer; //set dealer
   num_players=old.num_players; //set num players
   players=new player[num_players]; //make player array
   for (int i=0; i<num_players; i++){ //set players
      players[i]=old.players[i];
   }    
}
/*****************************************************
 *Function: ~game 
 *Description: game destructor deletes dynamically allocated memory
 *Parameters:none
 *Preconditions:memory was allocated dynamically
 *Postconditions: memory is deleted
 * *************************************************/
game::~game(){
   delete [] players;
}
/*****************************************************
 *Function: game operator  
 *Description: assignment operator overload
 *Parameters: address of old game to be copied
 *Preconditions: games have been initialized
 *Postconditions: second game's contents set to that of old
 * *************************************************/
void game:: operator=(const game & old){
   delete [] players; //delete player array
   cards=old.cards; //set deck
   game_dealer=old.game_dealer; //set dealer
   num_players=old.num_players; //set num players
   players=new player[num_players]; //make player array
   for (int i=0; i<num_players; i++){ //set players
      players[i]=old.players[i];
   }    
}

/*****************************************************
 *Function: play_game
 *Description: blackjack gameplay
 *Parameters: none
 *Preconditions: game had been made
 *Postconditions: blackjack has been played
 * *************************************************/
void game::play_game(){
   start_game(); //get player info 
   bool cont=true;
   while(cont==true){
      make_player_bets(); //get bets fom players
      deal_cards(); //deal cards
      player_hit_stay(); // asking playersto hit or stay
      dealer_gameplay(); // dealer's gameplay
      end_round(); //calculate winnings
      cont=play_again(); //play again?
      cout << endl;
      } 
   
}
/*****************************************************
 *Function: start_game
 *Description: gets number of players and starting money
 *Parameters: none
 *Preconditions: game has been made
 *Postconditions: num of players set, player array made, and ech plaer is allocated staring allowance
 * *************************************************/
void game::start_game(){
   cards.shuffle_deck(); //shuffle deck
   int starting_money;
   cout << "Welcome to Blackjack - the Game of 21" << endl;
   cout << "How many players will be participating? ";
   cin >> num_players; //getting num players
   set_players(num_players);
   cout << "How much money will players be starting out with? ";
   cin >> starting_money; //getting starting allowance
   for (int i=0; i<num_players; i++){ //giving players starting allowance
      players[i].set_playing_total(starting_money);
   }
}
/*****************************************************
 *Function: make_player_bets
 *Description: gets bets from players and makes sure bets are of less than or equal to current allowance
 *Parameters: none
 *Preconditions: players have been made
 *Postconditions: players bets set tovalid ints
 * *************************************************/
void game:: make_player_bets(){
   int temp_bet=0;
   for (int i=0; i<num_players; i++){ //iterate through players
      bool b=false;
      cout << "Player " << i+1 << ", you have $" << players[i].get_playing_total() << endl;
      cout << "Please place your bet: ";
      while(b==false){
         cin >>temp_bet;
         if (temp_bet> players[i].get_playing_total()){ //checking if bet is good
	    cout << "Invalid bet. Please enter an amount less than " << players[i].get_playing_total() << ": ";
	 }
	 else b=true;
      }
      players[i].set_bet(temp_bet);
   }
   cout << endl;
}
/*****************************************************
 *Function: deal_cards
 *Description: gives each player 2 cards and the dealer two cards
 *Parameters: none
 *Preconditions: deck and players have been made
 *Postconditions: players and dealer all have 2 cards
 * *************************************************/
void game::deal_cards(){
   cout << "Dealing cards:" << endl;
   for (int i=0; i<num_players; i++){ //iterating through players
      players[i].get_hand()->create_cards(2); //making space in hand for 2 cards to be dealt
   }
   game_dealer.get_hand()->create_cards(2); //making space in dealerhand to put 2 cards
   for (int i=0; i<num_players; i++){ //iterating through players
      for (int j=0; j<players[i].get_hand()->get_num_cards(); j++){ //iterating throughcards in hand 
         players[i].get_hand()->set_card(j,cards.get_card(cards.get_location())); //giving hand card
         cards.set_location(cards.get_location()+1);//increasing location in deck
      }
      
   }
   for (int i=0; i<game_dealer.get_hand()->get_num_cards(); i++){ //iterating through dealer's cards
      game_dealer.get_hand()->set_card(i,cards.get_card(cards.get_location())); //seting dealers cards
      cards.set_location(cards.get_location()+1); //incementing location in deck
   }
   for (int i=0; i<num_players; i++){ //printing each players hand
      cout << "Player " << i+1 << "'s hand: " << endl;
      players[i].print_hand();
      cout << endl;
   }
   cout << "Dealer's first card:" << endl;
   game_dealer.print_card_one(); //printing dealers first card
   cout << endl;

}
/*****************************************************
 *Function: player_hit_stay
 *Description: asks players if they want to hit or stay and how cards should be totaled if there is an ace
 *Parameters: none
 *Preconditions: players have ben made and dealt cards
 *Postconditions: players have gotten card totals
 * *************************************************/
void game::player_hit_stay(){
   int choice;
   for (int i=0; i<num_players; i++){ //iterating though players
      bool cont=true;
      while(cont==true){
         cout << "Player " << i+1 << " your current cards are:" << endl;
         players[i].print_hand();
         players[i].calculate_card_total();
         cout << "Your hand total is: " << players[i].get_card_total() << endl;
         cout << "Hit(1) or Stay(2)? ";
         cin >> choice;
         if (choice==1){ //if hit add card to hand and update card total
	    players[i].add_card(cards.get_card(cards.get_location()));
	    cards.set_location(cards.get_location()+1);
            players[i].print_hand();
	    players[i].calculate_card_total();
            cout << "Your hand total is: " << players[i].get_card_total() << endl;

	    cont=players[i].check_bust();
	 }
	 else cont=false; //if stay move on to next player
      }
   }
   cout << endl;
}
/*****************************************************
 *Function: dealer_gameplay
 *Description:  prints dealers hand and if totals less than 17 hits
 *Parameters: none
 *Preconditions: dealer has a hand containing cards
 *Postconditions: dealer 's total is updated
 * *************************************************/
void game::dealer_gameplay(){
   cout << "Dealer's cards:" << endl;
   game_dealer.print_all_cards();
   game_dealer.calculate_card_total();
   cout << "Dealer card total:" << game_dealer.get_card_total() << endl;
   bool hit=true;
   while(hit==true){
      if (game_dealer.get_card_total()>=17){ //dealer stays ends dealer gameplay
         hit=false;
      }
      else{
	 cout << "Dealer will hit" << endl;
         game_dealer.add_card(cards.get_card(cards.get_location())); //gets another card
	 cards.set_location(cards.get_location()+1); //update loction in deck
         cout << "Dealer's cards:" << endl;
         game_dealer.print_all_cards(); //print dealer's new hand
	 game_dealer.calculate_card_total();
         cout << "Dealer card total:" << game_dealer.get_card_total() << endl; //print dealer's new card total
     }
   }
}
/*****************************************************
 *Function: end_round
 *Description: updates player allowances based on card totals and dealer's card total
 *Parameters: none
 *Preconditions: players have card totals and bets
 *Postconditions: playing totals for all players updated
 * *************************************************/
void game:: end_round(){
   cout << "End of round, updating totals..." << endl;
   for (int i=0; i< num_players; i++){
      if (players[i].get_card_total()>21){ //player bust
         players[i].set_playing_total(players[i].get_playing_total()-players[i].get_bet());
      }
      else if(game_dealer.get_card_total()>21){ //dealer bust
	      players[i].set_playing_total(players[i].get_playing_total()+players[i].get_bet());	   
      }
     
      else{ //neither bust
         if (players[i].get_card_total()<game_dealer.get_card_total()){ //player less than dealer
	    players[i].set_playing_total(players[i].get_playing_total()-players[i].get_bet());
	 }
	 
	 else if (players[i].get_card_total()==21){ //player has 21
	    players[i].set_playing_total(players[i].get_playing_total()+( players[i].get_bet()/2)+players[i].get_bet());
	    
	 }
	 else if (players[i].get_card_total()>game_dealer.get_card_total()){ //player more than dealer
	    players[i].set_playing_total(players[i].get_playing_total()+players[i].get_bet());
	 }
      }
      cout << "Player " << i+1 << " $" << players[i].get_playing_total() << endl;
   }
   cards.populate_deck();
}

/*****************************************************
 *Function: play_again
 *Description:  return bool depending on if gameplay will continue
 *Parameters: none
 *Preconditions: game and members have been made
 *Postconditions: boo returned depending on if game will continue
 * *************************************************/
bool game:: play_again(){
   int choice;
   cout << "Continue? yes(1) no(2): ";
   cin >> choice;
   if (choice==1) return true;
   else return false;
}
