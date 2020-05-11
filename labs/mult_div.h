#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct m_d_values {
   int mult;
   float div;
};

bool valid_dimensions(char *m, char *n);
m_d_values **create_table(int m, int n);
void set_mult_values(m_d_values **table, int m, int n);
void set_div_values(m_d_values **table, int m, int n);
void print_tables(m_d_values **table, int m, int n);
void delete_table(m_d_values **table, int m);
bool recalc(char *argv[]);
    

