/**********************************************
 * Program Filename: game.cpp
 * Author: Erin Tanaka
 * Date: May 21, 2016
 * Description: game class implementation
 ********************************************/
#include "game.h"
#include <vector>
/********************************************
 * Function: game
 * Description: non default constructor
 * Parameters: int size for grid dimensions
 * Pre-Conditions: none
 * Post-Conditions: object made
 ******************************************/
game::game(int s){
   //ints
   arrows=3;
   size=s;
   //bools
   have_gold=false;
   wumpus_dead=false;
   player_dead=false;
   //pointers
   b1=new bats;
   b2=new bats;
   p1=new pit;
   p2=new pit;
   g=new gold;
   w=new wumpus;
   //make maze
   make_grid(s);
}
/********************************************
 * Function: make_grid
 * Description: makes vectors and sets event pointers
 * Parameters: int size for grid dimensions
 * Pre-Conditions: none
 * Post-Conditions: grid set up player starting point set
 ******************************************/
void game::make_grid(int s){
   for (int i=0; i<s; i++){ //setting up vector
      vector<room> row(s);
      grid.push_back(row);
   }
   for (int i=0; i<size; i++) {
      for (int j=0; j< size; j++){
         grid[i][j].set_bool(false);
	 grid[i][j].set_event(NULL);
      }
   }
   set_bats();
   set_pit();
   set_gold();
   set_wumpus();
   set_player_start();
   print_cheater_grid();
}
/********************************************
 * Function: set_bats
 * Description: sets bat pointers
 * Parameters: none
 * Pre-Conditions: grid made
 * Post-Conditions: pointers set
 ******************************************/
void game::set_bats(){
   int x, y;
   bool good=true;
   //bats: 2
      while (good==true){ //generates location
         x=rand() % size;
         y=rand() % size;
	 good=grid[x][y].get_bool();
      }
      grid[x][y].set_event(b1); //set event pointer
      grid[x][y].set_bool(true); //set bool
      
      good=true;
      while (good==true){ //generate location
         x=rand() % size;
         y=rand() % size;
	 good=grid[x][y].get_bool();
      }
      grid[x][y].set_event(b2); //set event pointer
      grid[x][y].set_bool(true); //set bool
}
/********************************************
 * Function: set_pit
 * Description: sets pit pointers
 * Parameters: none
 * Pre-Conditions: grid made
 * Post-Conditions: pointers set
 ******************************************/
void game::set_pit(){
   int x, y;
   bool good;
   //pits: 2
      good=true;
      while (good==true){ //generate location
         x=rand() % size;
         y=rand() % size;
	 good=grid[x][y].get_bool();
      }
      grid[x][y].set_event(p1); //set pointer
      grid[x][y].set_bool(true); //set bool
      
      good=true;
      while (good==true){ //genterat location
         x=rand() % size;
         y=rand() % size;
	 good=grid[x][y].get_bool();
      }
      grid[x][y].set_event(p2); //set pointer
      grid[x][y].set_bool(true); //set bool
}
/********************************************
 * Function: set_gold
 * Description: sets gold pointer
 * Parameters: none
 * Pre-Conditions: grid made
 * Post-Conditions: pointer set
 ******************************************/
void game::set_gold(){
   int x, y;
   bool good=true;
   //gold: 1
   while (good==true){ //generate location
      x=rand() % size;
      y=rand() % size;
      good=grid[x][y].get_bool();   
   }
   grid[x][y].set_event(g); //set pointer
   grid[x][y].set_bool(true); //set bool
}
/********************************************
 * Function: set_wumpus
 * Description: sets wumpus pointer
 * Parameters: none
 * Pre-Conditions: grid made
 * Post-Conditions: pointer set
 ******************************************/
void game::set_wumpus(){
   int x, y;
   bool good=true;
   //wumpus: 1
   while (good==true){ //generate location
      x=rand() % size;
      y=rand() % size;
      good=grid[x][y].get_bool();   
   }
   grid[x][y].set_event(w); //set pointer
   grid[x][y].set_bool(true); //set bool
   wstart_row=x;
   wstart_col=y;
}
/********************************************
 * Function: set_player_start
 * Description: sets starting location for player
 * Parameters: none
 * Pre-Conditions: grid made
 * Post-Conditions: location set
 ******************************************/
void game::set_player_start(){
   bool good=true;
   while (good==true){ //generate location
      start_row=rand() % size;
      start_col=rand() % size;
      good=grid[start_row][start_col].get_bool();
   }
      player_row=start_row; //set location
      player_col=start_col; //set location
}

/********************************************
 * Function: print_cheater_grid
 * Description: prints coordinates and event percept when location containes that event
 * Parameters: none
 * Pre-Conditions: grid made, events set
 * Post-Conditions: coordinaes and percepts printed to screen
 ******************************************/
void game::print_cheater_grid(){
   for (int i=0; i<size; i++){ //row
      for (int j=0; j<size; j++){ //col
	 if (grid[i][j].get_bool()==true){
	    grid[i][j].get_event()->message();
	 }
	 else{
	    cout << i << " " << j << endl;
	 }
      }
      cout << endl;
   }
   cout << "players starting position: " << player_row << " " << player_col << endl; 
}
/********************************************
 * Function: play_game
 * Description: game play
 * Parameters: none
 * Pre-Conditions: maze and player set
 * Post-Conditions: game played 
 ******************************************/
void game:: play_game(){
   cout << "starting gameplay" << endl;
   bool win=false;
   while (wumpus_dead==false && player_dead==false && arrows!=0){ //wumpus is alive player is alive still have arrows
      play_game_alive();
   }
   if (wumpus_dead==true){ //player alive and has enugh arrows
      while (win==false){
         play_game_dead();
	 if (have_gold==true && player_row==start_row && player_col==start_col) win=true;
	 if (player_dead==true) break;
      }
   }
   if (player_dead==true || arrows==0){
      prompt_new_game_death(); //end game
   }
   else prompt_new_game_win(); //end game
}
/*******************************************
 * Function: play_game_alive
 * Description: game play while wumpus is alive
 * Parameters: none
 * Pre-Conditions: maze and player set wumpus alive
 * Post-Conditions: player has either moved or shot an arrow 
 ******************************************/
void game::play_game_alive(){
   int choice;
   cout << endl;
   cout << "your current position as (row,col): " << player_row << " " << player_col << endl;
   print_messages();
   cout << "You have " << arrows << " arrow/s" << endl;
   cout << "Move(1) or shoot(2):";
   cin >> choice;
   if (choice==1) move_player();
   else player_shoot();
}

/*******************************************
 * Function: play_game_dead
 * Description: game play while wumpus is alive
 * Parameters: none
 * Pre-Conditions: maze and player set wumpus dead
 * Post-Conditions: player has moved 
 ******************************************/
void game::play_game_dead(){
   cout << endl;
   cout << "Current position as (row,col): " << player_row << " " << player_col << endl;
   print_messages();
   move_player();
}
/*******************************************
 * Function: move_player
 * Description: moves player nsew and clas for event function
 * Parameters: none
 * Pre-Conditions: maze and player set chose to move
 * Post-Conditions: player has move one space in designate direction
 ******************************************/
void game::move_player(){
   int choice;
   cout << "Move North(1), South(2), East(3), or West(4):";
   cin >> choice;
   if (choice==1){  //north
      if(player_row-1<0){
         cout << "There's a wall there." << endl;
      }
      else player_row--;
   }
   else if(choice==2){  //south
      if(player_row+1 > size-1){
         cout << "There's a wall there." << endl;
      }
      else player_row++;
   }
   else if (choice==3){ //east
      if (player_col+1>size-1){
         cout << "There's a wall there." << endl;
      }
      else player_col++;
   }
   else {
      if (player_col-1<0){  //west
         cout << "There's a wall there." << endl;
      }
      else player_col--;  
   }
   player_event();
}
/*******************************************
 * Function: player_shoot
 * Description: shoots arrow in one direction
 * Parameters: none
 * Pre-Conditions: chose to shoot
 * Post-Conditions: player shot an arrow in designated direction
 ******************************************/
void game::player_shoot(){
   int choice;
   cout << "Shoot North(1), South(2), East(3), or West(4):";
   cin >> choice;
   arrows--; //decrement arrows
   if(choice==1) shoot_north();
   else if (choice==2) shoot_south();
   else if (choice==3) shoot_east();
   else shoot_west();
}
/*******************************************
 * Function: shoot_north
 * Description: shoots arrow north
 * Parameters: none
 * Pre-Conditions: chose to shoot north
 * Post-Conditions: arrow shot if hit wumpus dies if miss calls scare 
 ******************************************/
void game::shoot_north(){
   bool hit=false;
   if(player_row-3<0){ //hit wall
      for (int i=player_row-1; i>=0; i--){
         if (grid[i][player_col].get_bool()==true && grid[i][player_col].get_event()->occurs()==4){
	    cout << "You shot and killed the wumpus." << endl;
	    wumpus_dead=true;
	    hit=true;
	 }
      }
   }
   else{ //3 spaces
      for(int i=player_row-1; i>=player_row-3; i--){
         if (grid[i][player_col].get_bool()==true && grid[i][player_col].get_event()->occurs()==4){
	    cout << "You shot and killed the wumpus." << endl;
	    wumpus_dead=true;
	    hit=true;
	 }
      }
   }
   if (hit==false) scare_wumpus(); //missed wumpus
}
/*******************************************
 * Function: shoot_south
 * Description: shoots arrow south
 * Parameters: none
 * Pre-Conditions: chose to shoot south
 * Post-Conditions: arrow shot if hit wumpus dies if miss calls scare 
 ******************************************/
void game::shoot_south(){
   bool hit=false;
   if(player_row+3>=size){ //hits wall
      for (int i=player_row+1; i<size; i++){
         if (grid[i][player_col].get_bool()==true &&grid[i][player_col].get_event()->occurs()==4){
	    cout << "You shot and killed the wumpus." << endl;
	    wumpus_dead=true;
	    hit=true;
	 }
      }
   }
   else{ //3 spaces
      for(int i=player_row+1; i<= player_row+3; i++){
         if (grid[i][player_col].get_bool()==true &&grid[i][player_col].get_event()->occurs()==4){
	    cout << "You shot and killed the wumpus." << endl;
	    wumpus_dead=true;
	    hit=true;
	 }
      }
   }
   if (hit==false) scare_wumpus(); //missed wumpus
}
/*******************************************
 * Function: shoot_east
 * Description: shoots arrow east
 * Parameters: none
 * Pre-Conditions: chose to shoot east
 * Post-Conditions: arrow shot if hit wumpus dies if miss calls scare 
 ******************************************/
void game::shoot_east(){
   bool hit=false;
   if(player_col+3>=size){ //hits wall
      for (int i=player_col+1; i<size; i++){
         if (grid[player_row][i].get_bool()==true && grid[player_row][i].get_event()->occurs()==4){
	    cout << "You shot and killed the wumpus." << endl;
	    wumpus_dead=true;
	    hit=true;
	 }
      }
   }
   else{ //3 spaces
      for(int i=player_col+1; i<= player_col+3; i++){
         if (grid[player_row][i].get_bool()==true && grid[player_row][i].get_event()->occurs()==4){
	    cout << "You shot and killed the wumpus." << endl;
	    wumpus_dead=true;
	    hit=true;
	 }
      }
   }
   if (hit==false) scare_wumpus(); //missed wumpus

}
/*******************************************
 * Function: shoot_west
 * Description: shoots arrow west
 * Parameters: none
 * Pre-Conditions: chose to shoot west
 * Post-Conditions: arrow shot if hit wumpus dies if miss calls scare 
 ******************************************/
void game::shoot_west(){
   bool hit=false;
   if(player_col-3<0){ //hit wall
      for (int i=player_col-1; i>=0; i--){
         if (grid[player_row][i].get_bool()==true && grid[player_row][i].get_event()->occurs()==4){
	    cout << "You shot and killed the wumpus." << endl;
	    wumpus_dead=true;
	    hit=true;
	 }
      }
   }
   else{ //3 spaces
      for(int i=player_col-1; i>=player_col-3; i--){
         if (grid[player_row][i].get_bool()==true && grid[player_row][i].get_event()->occurs()==4){
	    cout << "You shot and killed the wumpus." << endl;
	    wumpus_dead=true;
	    hit=true;
	 }
      }
   }
   if (hit==false) scare_wumpus(); //missed wumpus
}
/*******************************************
 * Function: scare_wumpus
 * Description: determines if wumpus gets scared and moves to a new spot int the grid
 * Parameters: none
 * Pre-Conditions: arrow is shot and misses
 * Post-Conditions: if wumpus gets scared moves to randomly generated location in the grid 
 ******************************************/
void game::scare_wumpus(){
   int scare, x, y;
   bool good=false;
   scare=rand() % 4;//if moves
   if (scare!=3){
      while (good==false){ //generates new location
        x=rand() % size;
        y=rand() % size;
	if (grid[x][y].get_bool()==false && (player_row!=x && player_col!=y)) good=true;
      }
      for (int i=0; i<size; i++){ //removes wumpus from old location
         for (int j=0; j<size; j++){
	    if (grid[i][j].get_bool()==true){
	       if (grid[i][j].get_event()->occurs()==4){
	          grid[i][j].set_bool(false);
		  grid[i][j].set_event(NULL);
	       }
	    }
	 }
      }
      grid[x][y].set_bool(true); //set bool
      grid[x][y].set_event(w); //set pointer
   }
}
/*******************************************
 * Function: player_event
 * Description: checks for event in players current locaion and calls appropriate function
 * Parameters: none
 * Pre-Conditions: game started events placed
 * Post-Conditions: appropriate event function called depending on which event if any is in player's location
 ******************************************/
void game::player_event(){
   bool evnt;
   int w;
   if (grid[player_row][player_col].get_bool()==true){ //location has an event
      w=grid[player_row][player_col].get_event()->occurs(); //which event
      if (w==1){ //gold
         game_gold();
      }
      else if (w==2){ //pit
	 game_pit();
      }
      else if (w==3){ //bats
	 game_bats();
      }
      else{ //wumpus
         game_wumpus();
      }
   }
}
/*******************************************
 * Function: game_gold
 * Description: picks up gold
 * Parameters: none
 * Pre-Conditions: player enters location containing gold
 * Post-Conditions: gold if not already picked up set to picked up
 ******************************************/
void game:: game_gold(){
   if (have_gold==false){
      have_gold=true;
      cout << "You picked up the gold." << endl;
      cout << endl;
   }
}
/*******************************************
 * Function: game_pit
 * Description: player dies
 * Parameters: none 
 * Pre-Conditions: player enters location with pit
 * Post-Conditions: player dies
 ******************************************/
void game:: game_pit(){
   cout << "You fell into a bottomless pit." << endl;
   player_dead=true;
}
/*******************************************
 * Function: game_bats
 * Description: moves player to random location in grid
 * Parameters: none
 * Pre-Conditions: player moves to location containing bats
 * Post-Conditions: player is moved to new location in grid
 ******************************************/
void game:: game_bats(){
   bool good=false;
   int nx, ny;
   while (good==false){
      nx=rand() % size;
      ny=rand() % size;
      if(nx==player_row && ny==player_col){}
      else{ //generated coordianates are not the same as current location
         player_row=nx;
	 player_col=ny;
	 good=true;
      }
   }
   cout << "Angry bats picked you up and dropped you in a different room." << endl;
   player_event();
}
/*******************************************
 * Function: game_wumpus
 * Description: player dies
 * Parameters: none
 * Pre-Conditions: player enters room with wumpus
 * Post-Conditions: player dies
 ******************************************/
void game:: game_wumpus(){
   if (wumpus_dead==false){
      cout << "You got eaten by the wumpus." << endl;
      player_dead=true;
   }
}
/*******************************************
 * Function: print_messages
 * Description: prints pecepts for surrounding rooms
 * Parameters: none
 * Pre-Conditions: events set
 * Post-Conditions: percepts printed to screen
 ******************************************/
void game::print_messages(){
   if ((player_row-1)>=0){ //northern message
      if (grid[player_row-1][player_col].get_bool()==true){ 
         if (grid[player_row-1][player_col].get_event()->occurs()==4 && wumpus_dead==true){}
	 else if (grid[player_row-1][player_col].get_event()->occurs()==1 && have_gold==true){}
         else grid[player_row-1][player_col].get_event()->message();
      }
   }
   if ((player_row+1)<size){ //southern message
      if (grid[player_row+1][player_col].get_bool()==true){ 
         if (grid[player_row+1][player_col].get_event()->occurs()==4 && wumpus_dead==true){}
	 else if (grid[player_row+1][player_col].get_event()->occurs()==1 && have_gold==true){}
	 else grid[player_row+1][player_col].get_event()->message();
      }
   
   }
   if ((player_col-1)>=0){ //west message
      if (grid[player_row][player_col-1].get_bool()==true){ 
         if (grid[player_row][player_col-1].get_event()->occurs()==4 && wumpus_dead==true){}
	 else if (grid[player_row][player_col-1].get_event()->occurs()==1 && have_gold==true){}
	 else grid[player_row][player_col-1].get_event()->message();
      }   
   }
   if ((player_col+1)<size){ //east message
      if (grid[player_row][player_col+1].get_bool()==true){ 
         if (grid[player_row][player_col+1].get_event()->occurs()==4 && wumpus_dead==true){}
	 else if (grid[player_row][player_col+1].get_event()->occurs()==1 && have_gold==true){}
	 else grid[player_row][player_col+1].get_event()->message();
   
      }
   }
}
/*******************************************
 * Function: prompt_new_game_death
 * Description: offers to playagain with same board again or different of quit altogether
 * Parameters: none
 * Pre-Conditions: player died
 * Post-Conditions: new game started with same boars, new game with new board or program ends
 ******************************************/
void game::prompt_new_game_death(){
   int choice;
   int replay;
   int old=size;
   cout << "You lose." << endl;
   cout << "Play again? Yes(1) No(2):";
   cin >> choice;
   if (choice==1){
      cout << "Replay board(1) or make a new one(2)?:";
      cin >> replay;
      if (replay==1){
         reset_board();
	 play_game();
      }
      else{
         reset_game();
         cout << "What size board? (4 or higher):";
	 cin >> size;
	 make_new_grid(old, size);
	 play_game();
      }
   }
   else{
      cout << "Thanks for playing" << endl;
   }
}
/*******************************************
 * Function: prompt_new_game
 * Description: prompts for new game or to quit
 * Parameters: none
 * Pre-Conditions: player won game
 * Post-Conditions: new game started with new board of specified size or game ends
 ******************************************/
void game::prompt_new_game_win(){
   int choice;
   int old=size;
   cout << "You won!" << endl;
   cout << "Play again? Yes(1) No(2):";
   cin >> choice;
   if (choice==1){
      reset_game();
      cout << " What size board? (4 or higher):";
      cin >> size;
      make_new_grid(old, size);
      play_game();
   }
   else{
      cout << "Thanks for playing" << endl;
   }
}
/*******************************************
 * Function: reset_game
 * Description: resets board and members for new game with different board as previous
 * Parameters: none
 * Pre-Conditions: new game with new board chosen
 * Post-Conditions: board cleared, arrows set to 3, and bools set to false
 ******************************************/
void game::reset_game(){
   cout << "reset game" << endl;
   for (int i=0; i<size; i++){ //row
      for (int j=0; j<size; j++){ //col
         if (grid[i][j].get_bool()==true){
	    grid[i][j].set_event(NULL); //set pointer
	    grid[i][j].set_bool(false); //set bool
	 }
      }
   }
   arrows=3;
   have_gold=false;
   player_dead=false;
   wumpus_dead=false;
}
/*******************************************
 * Function: reset_board 
 * Description: resets board and members for new game with same board as previous
 * Parameters: none
 * Pre-Conditions: new game with same board chosen
 * Post-Conditions: arrows and bools reset, player set back to start, and resets wumpus
 ******************************************/
void game::reset_board(){
   arrows=3;
   have_gold=false;
   player_dead=false;
   wumpus_dead=false;

   player_row=start_row;
   player_col=start_col;

   for (int i=0; i<size; i++){
      for (int j=0; j<size; j++){
         if (grid[i][j].get_bool()==true && grid[i][j].get_event()->occurs()==4){ 
	    grid[i][j].set_bool(false); //set bool 
	    grid[i][j].set_event(NULL); //sset pointer
	 }
      }
   }

   grid[wstart_row][wstart_col].set_event(w);
   grid[wstart_row][wstart_col].set_bool(true);
}
/**************************************
 * Function: make_new_grid
 * Description: resizes vectors and sets up evnets
 * Parameters: size of old grid and size of new
 * Pre-Conditions: grid already has been made 
 * Post-Conditions: vectors resied and events set
 * **********************************/
void game::make_new_grid(int old, int new_size){
   if (old-new_size==0){ //same size
   
   }
   else{ //new is bigger
      grid.resize(new_size);
      for (int i=0; i<new_size; i++){
         grid[i].resize(new_size);
      }
   }
   for (int i=0; i<new_size; i++) {
      for (int j=0; j< new_size; j++){
         grid[i][j].set_bool(false);
	 grid[i][j].set_event(NULL);
      }
   }
   set_bats();
   set_pit();
   set_gold();
   set_wumpus();
   set_player_start();
}
