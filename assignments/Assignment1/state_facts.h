#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

struct county{
   string name;  //name of county
   string * city;  //name of cities
   int cities;  //number of cities in county
   int population; //total pop of county
   float avg_income;  //avg household income
   float avg_house;  //avg household price
};

struct state{
   string name;  //name of state
   struct county * c; //name of counties
   int counties;  //number of counties
   int population;  //total population of state
};

bool is_valid_arguments(char*[], int);
void prompt_num_state(char* [], int);
void prompt_file(char* [], int);
state * create_states(int);
void get_state_data(state *, int, ifstream &);
county * create_counties(int);
void get_county_data(county *, int, ifstream &);
string * create_cities(int);
void get_city_names(string *, int, ifstream &);
void delete_info(state *, int);
void state_largest_pop(state*, int);
void county_largest_pop(state*, int);
void county_income(state*, int);
void avg_house_cost(state*, int);
void sort_state_alpha(state*, int);
void sort_state_pop(state*, int);
void sort_county_alpha(state*, int);
void sort_county_pop(state*, int);
void check_next_letters(state *, int);
