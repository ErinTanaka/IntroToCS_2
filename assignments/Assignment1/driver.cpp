/*********************************************
 * Program: driver.cpp
 * Author: Erin Tanaka
 * Date: 4/10/2016
 * Description: processes information about states and prints specific info about them 
 * Input: commandline arguments for number of states and file to get state info from
 * Output: info about states in order by population alphabetically etc.
 * *****************************************/

#include "./state_facts.h"

int main(int argc, char* argv[]){
 
   ifstream file;     
   state *list;
   int n;      
   bool c; 
   cout << "checking args" << endl;
   c=is_valid_arguments(argv, argc);
   if (c==false) exit(1);
      
   file.open(argv[4]);
   n=atoi(argv[2]);
   list=create_states(n);
   get_state_data(list, n, file);
   file.close();
   state_largest_pop(list , n);	      
   county_largest_pop(list, n);	       
   county_income(list, n);	        
   avg_house_cost(list, n);	         
   sort_state_alpha(list, n);	           
   sort_state_pop(list, n);	            
   sort_county_alpha(list, n);		     	     
   sort_county_pop(list, n);		           
   delete_info(list, n);		        
   return 0;
}
