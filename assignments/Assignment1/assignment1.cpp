#include "./state_facts.h"


/***************************************************************************
 * Name: is_valid_arguments
 * Description: checks if command line arguments are valid
 * Parameters: number of arguments, and array of arguments
 * Preconditions: program is executed
 * Postconditions: true retuned if arguments are good false if they are bad
 * ************************************************************************/
bool is_valid_arguments(char* argv[], int c){
   int state=-1, file=-1;
   ifstream myfile;
   if(c!=5){
      cout << "invalid nmber of arguments, exiting program" << endl;
      return false;
   }
   for (int i=1; i<c; i+=2){
       if(strcmp(argv[i],"-s")==0 && state==-1){
	  if(atoi(argv[i+1])<=0) prompt_num_state(argv, i+1);	         
       }
       else if(strcmp(argv[i],"-f")==0 && file==-1){
	  myfile.open(argv[i+1]);
	  if(myfile.is_open()); 
	  else prompt_file(argv, i+1);
	          
       }	        
       else{          
	  cout << " invalid arguments exiting program" << endl;
	             return false;	           
       }
	   
   }
   return true;
   
}
/***************************************************************************
 * Name: prompt_num_state
 * Description: reprompts user for a valid number of states
 * Parameters: array of arguments location of int saying number of states
 * Preconditions: user enterd an invalid number of states
 * Postconditions: valid number of states gets entered by user and is stored in array
 * ************************************************************************/
void prompt_num_state(char* argv[], int c){
   while(atoi(argv[c])<=0){
      cout << "enter a number of states: ";
      cin>>argv[c];
   }   
}

/***************************************************************************
 * Name: prompt_file
 * Description: reprompts user for valid file name 
 * Parameters: array of arguments location of int saying number of states
 * Preconditions: user entered an invalid file name
 * Postconditions: valid file name saved to array of arguments
 * ************************************************************************/
void prompt_file(char* argv[], int c){     
   ifstream file;
   do {     
      cout << "enter a valid file name: ";
      cin >> argv[c];
      file.open(argv[c]);
   } while (!file.is_open());      
}
      
/***************************************************************************
 * Name: create_states
 * Description: dynamically allocates memory for list of states
 * Parameters: number of states to be made
 * Preconditions: user entered a valid number of states
 * Postconditions: array of s states is made and pointer to first element returned
 * ************************************************************************/
state * create_states(int s){
   state* list;
   list=new state[s];
   return list;
}

/***************************************************************************
 * Name: get_state_data
 * Description: sets members of structs eual to stats supplied from file 
 * Parameters: file to get information from, number of states and array of states
 * Preconditions: state array has been made
 * Postconditions: members are set to stats
 * ************************************************************************/
void get_state_data(state * s_list, int s, ifstream &file){
   for (int i=0; i<s; i++){
      file >> s_list[i].name;
      file >> s_list[i].population;
      file >> s_list[i].counties;
      s_list[i].c=create_counties(s_list[i].counties);
      get_county_data(s_list[i].c, s_list[i].counties, file);
   }
}

/***************************************************************************
 * Name: create_countries
 * Description: dynamically allocates memory for list of states
 * Parameters: numbers of counties in state
 * Preconditions: state has been made and filled with information
 * Postconditions: pointer to array of counties returned
 * ************************************************************************/
county * create_counties(int c){
   county * c_list;
   c_list= new county[c];
   return c_list;
}

/***************************************************************************
 * Name: get_county_data
 * Description: sets members of structs eual to stats supplied from file 
 * Parameters: pointer to array of counties, number of counties, file to get info from
 * Preconditions: counties were created
 * Postconditions: members of counties are set to stats from file 
 * ************************************************************************/
void get_county_data(county * c_list, int c, ifstream &file){
   for (int i=0; i<c; i++){
      file >> c_list[i].name;
      file >> c_list[i].population;
      file >> c_list[i].avg_income;
      file >> c_list[i].avg_house;
      file >> c_list[i].cities;
      c_list[i].city= create_cities(c_list[i].cities);
      get_city_names(c_list[i].city, c_list[i].cities, file);
   }   
}

/***************************************************************************
 * Name: create_cities
 * Description: dynamically allocates memory for list of names of cities
 * Parameters: number of cities
 * Preconditions: counties were created and filled with data
 * Postconditions: pointer to list of cities is returned
 * ************************************************************************/
string * create_cities(int cty){
   string *cty_list;
   cty_list= new string[cty];
   return cty_list;
}

/***************************************************************************
 * Name: get_city_names
 * Description: sets the names of cities
 * Parameters: file to get info from, number of cities, pointer to list of cities
 * Preconditions: memory for cities has been allocated
 * Postconditions: array contains names of cities for county
 * ************************************************************************/
void get_city_names(string *cty_list, int cty, ifstream &file){
   for (int i=0; i<cty; i++){
   file >> cty_list[i];
   }
}

/***************************************************************************
 * Name: delete_info
 * Description: deletes previously allocated memory off of the heap
 * Parameters: pointer to array of states and number of states
 * Preconditions: memory was previously allocated
 * Postconditions: info on heap is deleted
 * *************************************************************************/
void delete_info(state *list, int s){
   for (int i=0; i<s; i++){
      for (int j=0; j<list[i].counties; j++){
	 delete [] list[i].c[j].city;
      }
      delete [] list[i].c;
   }
   delete [] list;
}

/***************************************************************************
 * Name: state_largest_pop
 * Description: prints state with the largest population
 * Parameters: pointer to list of states and number of states
 * Preconditions: states and sequential arrays have been created and members filled properly
 * Postconditions: state with largest population is printed
 * *************************************************************************/
void state_largest_pop(state* list , int s){
   int temp=list[0].population;
   string n=list[0].name;
   for (int i=1; i<s; i++){
      if (list[i].population>temp){
         temp=list[i].population;
	 n=list[i].name;
      }  
   }
  cout << "State with largest population: " << n << "-" << temp << endl;
  cout << "\n";
}

/***************************************************************************
 * Name: county_largest_pop
 * Description: prints the county with the largest population
 * Parameters: pointer to list of states and number of states
 * Preconditions: states and sequential arrays have been created and members filled properly
 * Postconditions: county with largest population is printed to screen
 * *************************************************************************/
void county_largest_pop(state* list, int s){
   int temp=list[0].c[0].population;
   string n=list[0].c[0].name;
   for (int i=0; i<s; i++){
      for (int j=0; j<list[i].counties; j++){
         if (list[i].c[j].population>temp){
	    temp=list[i].c[j].population;
	    n=list[i].c[j].name;
	 }
      }
   }
   cout << "County with largest population: " << n << " - " << temp << endl;
   cout << endl;
}
/****************************************************************************
 * Name: county_income
 * Description: prints counties with incomes above user entered number
 * Parameters: pointer to list of states and number of states
 * Preconditions: states and sequential arrays have been created and members filled properly
 * Postconditions: counties with income above user entered value get printed to screen
 * *************************************************************************/
void county_income(state* list, int s){
   int temp;
   cout << "Please enter a minimum average income for counties:";
   cin >> temp;

   for (int i=0; i<s; i++){
      for (int j=0; j<list[i].counties; j++){
         if (list[i].c[j].avg_income>=temp){
	    cout << list[i].c[j].name << " - " << list[i].c[j].avg_income << endl;
	 }
      }
   }
   cout << endl;
}
/***************************************************************************
 * Name: avg_house_cost
 * Description: prints avg house cost per state
 * Parameters: pointer to list of states and number of states
 * Preconditions: states and sequential arrays have been created and members filled properly
 * Postconditions: avg house costs are printed to screen
 * ************************************************************************/
void avg_house_cost(state* list, int s){
   cout << "Average house cost per state:" << endl;
      int total, avg;
   for (int i=0; i<s; i++){
      total=0;
      for (int j=0; j<list[i].counties; j++){
	 total=list[i].c[j].avg_house + total;
      }
      avg=total/list[i].counties; 
      cout << list[i].name << ": $" << avg << endl;
   }
   cout << endl;
}
/***************************************************************************
 * Name: sort_state_alpha
 * Description: sorts states alphabetically and prints them to screen
 * Parameters: pointer to list of states and number of states
 * Preconditions: states and sequential arrays have been created and members filled properly
 * Postconditions: list of states printed in alphabetical order
 * ************************************************************************/
void sort_state_alpha(state * list, int s){
   
   cout << "States alphabetized: ";
   state temp;
   int count=0;
   while(count<s){
      for (int i=s-1; i>0; i--){
         if(list[i].name[0]< list[i-1].name[0]){
            temp=list[i];
	    list[i]=list[i-1];
	    list[i-1]=temp;
         }
      }
      count++;
   }
   for (int i=0; i<s; i++){
      cout << list[i].name << ", ";
   }
   cout << endl;
   cout << endl;
}

/***************************************************************************
 * Name: sort_state_pop
 * Description: sorts states by population least to greatest
 * Parameters: pointer to list of states and number of states
 * Preconditions: states and sequential arrays have been created and members filled properly
 * Postconditions: states printed in order of population least to greatest
 * ************************************************************************/
void sort_state_pop(state* list, int s){
   cout << "States by population :";
   state temp;
   int count =0;
      for (int i=0; i<s; i++){
         for (int j=0; j<s-1-i; j++){
            if(list[j].population>list[j+1].population){
	       cout << "making swap" << endl;
	       temp=list[j];
	       list[j]=list[j+1];
	       list[j+1]=temp;
	    }
         }
      } 
   for (int i=0; i<s; i++){
      cout << list[i].name << ", ";
   } 
   cout << endl;
   cout << endl;
}
/***************************************************************************
 * Name: sort_county_alpha
 * Description: prints counties alphabetically in each state
 * Parameters: pointer to list of states and number of states
 * Preconditions: states and sequential arrays have been created and members filled properly
 * Postconditions: state is printed followed by the counties int state in alphabetical order 
 * ************************************************************************/
void sort_county_alpha(state* list, int s){
   cout << "Counties within each state alphabetically:" << endl;

   county temp;
      for (int i=0; i<s; i++){
         for (int c=0; c<list[i].counties-1; c++){
	    for (int k=0; k<list[i].counties-1; k++){
               if(list[i].c[k].name[0]>list[i].c[k+1].name[0]){
		  temp=list[i].c[k];
	          list[i].c[k]=list[i].c[k+1];
	          list[i].c[k+1]=temp;
	       }   
	    }
	 }	 
      }
   for (int i=0; i<s; i++){
      cout << list[i].name << ": ";
      for (int j=0; j<list[i].counties; j++){
         cout << list[i].c[j].name << ", ";
      }
      cout << endl;
   }
   cout << endl;
} 
/***************************************************************************
 * Name: county_pop
 * Description: sorts counties with in each state by population and prints them to screen
 * Parameters: pointer to list of states and number of states
 * Preconditions: states and sequential arrays have been created and members filled properly
 * Postconditions: state and its counties in order by population printed
 * ************************************************************************/

void sort_county_pop(state* list, int s){
  cout << "County by population in each state:"<< endl;
   county temp;
   for (int i=0; i<s; i++){
      for (int j=0; j<list[i].counties; j++){
         for (int k=0; k<list[i].counties-1-j; k++){
            if(list[i].c[k].population>list[i].c[k+1].population){
	       temp=list[i].c[k];
	       list[i].c[k]=list[i].c[k+1];
	       list[i].c[k+1]=temp;
	    }
         }
      }
   }  
   for (int i=0; i<s; i++){
      cout << list[i].name << ": ";
      for (int j=0; j< list[i].counties; j++){
         cout << list[i].c[j].name << ", ";
      }
      cout << endl;
   }
   
   cout << endl;
}

