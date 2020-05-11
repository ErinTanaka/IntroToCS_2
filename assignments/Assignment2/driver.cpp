#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "dealer.h"
#include "game.h"
int main(){
   srand(time(NULL));
   game blkjk;
   blkjk.play_game();
   cout << "Thanks for playing!" << endl;
   return 0;
}
