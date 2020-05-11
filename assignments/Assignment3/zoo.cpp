/*********************************************
 *Program: zoo.cpp
 *Author: Erin Tanaka
 *Date: 5/6/16
 *Description: Implementation for zoo class 
 * ******************************************/
#include "zoo.h"

/*********************************************
 *Function: zoo (default)
 *Description: default constructor for zoo
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: zoo object created arrays set to null, bool to false and int values to 0
 * ******************************************/
zoo::zoo(){
   bank=0;
   p_exhibit=NULL;
   b_exhibit=NULL;
   t_exhibit=NULL;
   penguins=0;
   bears=0;
   tigers=0;
   bonus=false;
   bonus_val=0;
}
/*********************************************
 *Function: zoo (nondefault)
 *Description: non defuault constructor
 *Parameters: int for number of animals the user wants to start the zoo with
 *Pre-Conditions; none
 *Post-Conditions: zoo made with 100000 in bank exhibits with specified num of animals
 * ******************************************/
zoo::zoo(int n){
   bank=100000-(n*16000);
   p_exhibit=new penguin[n];
   b_exhibit=new polarbear[n];
   t_exhibit=new tiger[n];
   penguins=n;
   bears=n;
   tigers=n;
   bonus=false;
   bonus_val=0;
}
/*********************************************
 *Function: day
 *Description: plays game feeds animals random event  
 *Parameters: none
 *Pre-Conditions: zoo has been created
 *Post-Conditions: one day has been played and continues to play until user decides to end game
 * ******************************************/
void zoo::day(){
   bool play=true;
   bool endday=false;
   int choice;
   while (play==true){
      cout << endl;
      endday=false;
      bonus=false;
      cout << "It's a new day!" << endl;
      age_up_animals();
      print_animals();
      feed_animals();
      random_event();
      payout();
      cout << "It's the end of the day would you like to purchase a new animal (1), start a new day (2) or end the game(3): ";
      while(endday==false){
         cin >> choice;
         if (choice==1 && bank>=1000){
	    buy_animal();
	    endday=true;
	 } 
         else if (choice==1 && bank<1000){
            cout << "You don't have enough money to buy any animals" << endl;
         }
	 else if (choice==2) endday=true;
         else if(choice==3) {
            cout << "Thanks for playing" << endl;
            play=false;
	    break;
         }
      }
   }
}
/*********************************************
 *Function: age up animals
 *Description: increase the age of all animals in zoo
 *Parameters: none
 *Pre-Conditions: there are animals in exhibits
 *Post-Conditions: all animals ages increased by one
 * ******************************************/
void zoo::age_up_animals(){
   for (int i=0; i< tigers; i++){
      t_exhibit[i].age_up();
   }
   for (int i=0; i< bears; i++){
      b_exhibit[i].age_up();
   }
   for (int i=0; i< penguins; i++){
      p_exhibit[i].age_up();
   }
}
/*********************************************
 *Function: print animals
 *Descrition: prints number of animals in each exhibit
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: number of each animal printed to screen
 * ******************************************/
void zoo::print_animals(){
   int numtigers=0;
   int babytigers=0;
   int numbears=0;
   int babybears=0;
   int numbirds=0;
   int babybirds=0;
   if (tigers>0){
      for(int i=0; i<tigers; i++){
         if (t_exhibit[i].get_age()<=3) babytigers++;
	 else numtigers++;
      }
      cout << "Adult tigers: " << numtigers << endl;
      cout << "Baby tigers: " << babytigers << endl;
   }
   else cout << "No tigers" << endl;

   if (bears>0){
      for(int i=0; i<bears; i++){
         if (b_exhibit[i].get_age()<=3) babybears++;
	 else numbears++;
      }
      cout << "Adult polar bears: " << numbears << endl;
      cout << "Baby polar bears: " << babybears << endl;
   }
   else cout << "No polarbears" << endl;

   if (penguins>0){
      for(int i=0; i<penguins; i++){
         if (p_exhibit[i].get_age()<=3) babybirds++;
	 else numbirds++;
      }
      cout << "Adult penguins: " << numbirds << endl;
      cout << "Baby penguins: " << babybirds << endl;
   }
   else cout << "No penguins" << endl;
}
/*********************************************
 *Function: feed animals
 *Description: calculates food costs for all animals and subtracts from bank
 *Parameters: none
 *Pre-Conditions: animal arrays contain animals
 *Post-Conditions: bank total is decremented by total food costs to feed all animals
 * ******************************************/
void zoo::feed_animals(){
   int temp=0;
   for (int i=0; i< penguins; i++){
      temp=temp+p_exhibit[i].get_food();
   }
   for (int i=0; i< bears; i++){
      temp=temp+b_exhibit[i].get_food();
   }
   for (int i=0; i< tigers; i++){
      temp=temp+t_exhibit[i].get_food();
   }
   cout << "Total food costs are: $ " << temp << endl;
   bank=bank-temp;
   cout << "Updated bank total: $ " << bank << endl;

}
/*********************************************
 *Function: payout
 *Description: calculates payout per animaland adds it to the total
 *Parameters: none
 *Pre-Conditions: zoo has animals
 *Post-Conditions: bank pdated with payout for all animals
 * ******************************************/
void zoo::payout(){
   int temp=0;
   for (int i=0;i<penguins; i++){
      if (p_exhibit[i].get_age()<=3){
         temp=temp+p_exhibit[i].get_payout()*2;
      }
      else temp=temp+p_exhibit[i].get_payout();
   }
   for (int i=0;i<bears; i++){
      if (b_exhibit[i].get_age()<=3){
         temp=temp+b_exhibit[i].get_payout()*2;
      }
      else temp=temp+b_exhibit[i].get_payout();
   }
   if (bonus==true){
      for (int i=0; i<tigers; i++){
         temp=temp+t_exhibit[i].bonus_payout(bonus_val);
      }
   }
   else{
      for (int i=0;i<tigers; i++){
         if (t_exhibit[i].get_age()<=3){
            temp=temp+t_exhibit[i].get_payout()*2;
         }
         else temp=temp+t_exhibit[i].get_payout();
      }
   }

   cout << "Today's earnings were: $ " << temp << endl;
   bank=bank+temp;
   cout << "Updated bank total: $ " << bank << endl;
}
/*********************************************
 *Function: random event
 *Description: generates random number to determine random event
 *Parameters: none
 *Pre-Conditions: zoo has been made
 *Post-Conditions: event function is called depending on number generated
 * ******************************************/
void zoo::random_event(){
   int event;
   event=rand() % 4;
   if (event==0){
      sickness();
   }
   else if (event==1){
      boom();
   }
   else if (event==2){
      baby_born();
   }
   else{
      cout << "Nothing special happened today" << endl;
   }
}
/*********************************************
 *Function: sickness
 *Description: an animal dies of sickness from an exhibit of user's choosing
 *Parameters: none
 *Pre-Conditions: random event generated
 *Post-Conditions: one animal removed from exhibit
 * ******************************************/
void zoo::sickness(){
   int choice, loc, cost;
   bool good=false;
   cout << "A sickness has broken out in your zoo" << endl;
   while (good==false){
      cout << "Which exhibit will be effected tiger(1), polar bear(2), penguin(3): ";
      cin >> choice;
      if (choice==1 && tigers>0){
         loc=rand() % tigers;
	 if (t_exhibit[loc].get_age()<=3) cost=t_exhibit[loc].get_payout()*2;
	 else cost=t_exhibit[loc].get_payout();
         shrink_tiger(loc);
	 good=true;
      }
      else if(choice==2 && bears>0){
         loc=rand() % bears;
	 if (b_exhibit[loc].get_age()<=3) cost=b_exhibit[loc].get_payout()*2;
	 else cost=b_exhibit[loc].get_payout();
         shrink_bear(loc);
	 good=true;
      }
      else if (choice==3 && penguins>0){
         loc=rand() % penguins;
	 if (p_exhibit[loc].get_age()<=3) cost=p_exhibit[loc].get_payout()*2;
	 else cost=p_exhibit[loc].get_payout();
         shrink_bird(loc);
	 good=true;
      }
   }
   cout << "You lost $" << cost << endl;
   bank=bank-cost;
   cout << "Updated bank total: $" << bank << endl; 
}
/*********************************************
 *Function: boom
 *Description: there is a boom in attendance and tigers generate a bonus for payout
 *Parameters: none
 *Pre-Conditions: event's number was generated when making random event
 *Post-Conditions: random value between 250 and 500, bonus set to true and bonus val set to gnerated bonus
 * ******************************************/
void zoo::boom(){
   int n;
   cout << "The zoo was especially popular today!" << endl;
   n=rand() % 250 + 250;
   bonus=true;   
   bonus_val=n;
}
/*********************************************
 *Function: baby born
 *Description: animal age 0 is added t user specified exhibit if there is an animal that is of age to reproduce
 *Parameters: none
 *Pre-Conditions: events number is generated in random event function
 *Post-Conditions: animal is added to specified exhibit age permitting
 * ******************************************/
void zoo::baby_born(){
   int choice;
   bool a=false;   
   cout << "An animal is having a baby/babies!" <<  endl;
   while (a==false){
      cout << "Which type of animal had a baby/babies, tiger(1), polar bear(2), penguin(3): ";
      cin >> choice;
      if (choice==1) a=check_tiger_age();
      else if (choice==2) a=check_bear_age();
      else a=check_penguin_age();
   }
//   cout << "made it out of the loop" << endl;
   if (choice==1) expand_tiger(true);
   else if (choice==2){
      expand_bear(true);
      expand_bear(true);
   }
   else{
      expand_bird(true);
      expand_bird(true);
      expand_bird(true);
   } 
}
/*********************************************
 *Function: check tiger age
 *Description: checks if there is a tiger of  age 4
 *Parameters: none
 *Pre-Conditions: there are tigers in the exhibit
 *Post-Conditions: bool true is returned if a tiger is old enough, false if not
 * ******************************************/
bool zoo::check_tiger_age(){
//   cout << "checking tiger age" << endl;
   for (int i=0; i<tigers; i++){
      if (t_exhibit[i].get_age()>3) return true;
   }
   return false;
}
/*********************************************
 *Function: check bear age
 *Description: checks if there is a polar bear of  age 4
 *Parameters: none
 *Pre-Conditions: there are polar bears in the exhibit
 *Post-Conditions: bool true is returned if a bear is old enough, false if not
 * ******************************************/
bool zoo::check_bear_age(){
//   cout << "checking bear  age" << endl;
   for (int i=0; i<bears; i++){
      if (b_exhibit[i].get_age()>3) return true;
   }
   return false;
}
/*********************************************
 *Function: check penguin age
 *Description: checks if there is a penguin of  age 4
 *Parameters: none
 *Pre-Conditions: there are penguins in the exhibit
 *Post-Conditions: bool true is returned if a penguin is old enough, false if not
 * ******************************************/
bool zoo::check_penguin_age(){
//   cout << "checking penguin age" << endl;
   bool a=false;
   for (int i=0; i<penguins; i++){
      if (p_exhibit[i].get_age()>3) return true;
   }
   return false;
}
/*********************************************
 *Function: buy animal
 *Description: allows user to purchase an animal if they have enough money
 *Parameters: none
 *Pre-Conditions: user chose to buy an animal
 *Post-Conditions: another animal is added to specified exhibit and money subtracted from bank
 * ******************************************/
void zoo::buy_animal(){
   int choice;
   bool good=false;
   cout << "Buy an animal" << endl;
   cout << "Tiger-$10000 (1)" << endl;
   cout << "Polar bear-$5000 (2)" << endl;
   cout << "Penguin-$1000 (3)" << endl;
   while (good==false){
      cout << "Enter the number of the animal you wish to purchase: ";
      cin >> choice;
         if (choice==1 && 10000<=bank){
            expand_tiger(false);
	    good=true;
         }
         else if(choice==2 && 5000<=bank ){
            expand_bear(false);
	    good=true;
         }
         else if (choice==3 && 1000<=bank){
            expand_bird(false);
	    good=true;
         }
   }
}
/*********************************************
 *Function: expand bird
 *Description: adds penguin to pengin exhibit
 *Parameters: bool determining if animal being made/added is a baby
 *Pre-Conditions: either an animal was purchased or born
 *Post-Conditions: penguin added to exhibit of either age 0 or 3
 * ******************************************/
void zoo::expand_bird(bool baby){
   penguins++;
   penguin* temp;
   temp=new penguin[penguins];
   for (int i=0; i<penguins-1; i++){
      temp[i]=p_exhibit[i];
   }
   if (baby==true){
      temp[penguins-1].set_age(0);
   }
   delete[] p_exhibit;
   p_exhibit=temp;
}
/*********************************************
 *Function: expand bear
 *Description: adds polar bear to polar bear exhibit
 *Parameters: bool determining if animal being made/added is a baby
 *Pre-Conditions: either an animal was purchased or born
 *Post-Conditions: bear added to exhibit of either age 0 or 3
 * ******************************************/
void zoo::expand_bear(bool baby){
   bears++;
   polarbear* temp;
   temp=new polarbear[bears];
   for (int i=0; i<bears-1; i++){
      temp[i]=b_exhibit[i];
   }
   if (baby==true){
      temp[bears-1].set_age(0);
   }
   delete[] b_exhibit;
   b_exhibit=temp;
}
/*********************************************
 *Function: expand tiger
 *Description: adds tiger to tiger exhibit
 *Parameters: bool determining if animal being made/added is a baby
 *Pre-Conditions: either an animal was purchased or born
 *Post-Conditions: tiger added to exhibit of either age 0 or 3
 * ******************************************/
void zoo::expand_tiger(bool baby){
   tigers++;
   tiger* temp;
   temp=new tiger[tigers];
   for (int i=0; i<tigers-1; i++){
      temp[i]=t_exhibit[i];
   }
   if (baby==true){
      temp[tigers-1].set_age(0);
   }
   delete[] t_exhibit;
   t_exhibit=temp;
}
/*********************************************
 *Function: shrink bird
 *Description: removes one penguin from exhibit
 *Parameters: location in array of penguin to be removed
 *Pre-Conditions: sickness has occured and effected penguins
 *Post-Conditions: one penguin is removed from exhibit
 * ******************************************/
void zoo::shrink_bird(int loc){
   penguin* temp;
   temp=new penguin[penguins-1];
   int l=0;
   for (int i=0; i<penguins; i++){
      if (i!=loc){
//	 cout << l << " " << i << endl;
	 temp[l]=p_exhibit[i];
	 l++;
      }
   }
   
   delete [] p_exhibit;
   p_exhibit=temp;
   penguins--;
}
/*********************************************
 *Function: shrink bear
 *Description: removes one polar bear from exhibit
 *Parameters: location in array of polar bears to be removed
 *Pre-Conditions: sickness has occured and effected polar bears
 *Post-Conditions: one polar bears is removed from exhibit
 * ******************************************/
void zoo::shrink_bear(int loc){
   polarbear* temp;
   temp=new polarbear[bears-1];
   int l=0;
   for (int i=0; i<bears; i++){
      if (i!=loc){
//	 cout << l << " " << i << endl;
	 temp[l]=b_exhibit[i];
	 l++;
      }
   }
   delete [] b_exhibit;
   b_exhibit=temp;
   bears--;
}
/*********************************************
 *Function: shrink tiger
 *Description: removes one tiger from exhibit
 *Parameters: location in array of tigers to be removed
 *Pre-Conditions: sickness has occured and effected tigers
 *Post-Conditions: one tigers is removed from exhibit
 * ******************************************/
void zoo::shrink_tiger(int loc){
   tiger* temp;
   temp=new tiger[tigers-1];
   int l=0;
   for (int i=0; i<tigers; i++){
      if (i!=loc){
//	 cout << l << " " << i << endl;
	 temp[l]=t_exhibit[i];
	 l++;
      }
   }
   delete [] t_exhibit;
   t_exhibit=temp;
   tigers--;
}


/*********************************************
 *Function: zoo (destructor)
 *Description: deletes dynamically allocated memory
 *Parameters: none
 *Pre-Conditions: zoo goes out of scope
 *Post-Conditions: dynamic memory is freed
 * ******************************************/
zoo::~zoo(){
   delete [] p_exhibit;
   delete [] b_exhibit;
   delete [] t_exhibit;
}

