#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct m_d_values{
    int mult;
    float div;
};

//Prototypes

bool valid_dimensions(char *m, char *n);
m_d_values **create_table(int m, int n);
void set_mult_values(m_d_values **table, int m, int n);
void set_div_values(m_d_values **table, int m, int n);
void print_tables(m_d_values **table, int m, int n);
void delete_table(m_d_values **table, int m);
bool recalc(char *argv[]);

int main(int argc, char *argv[]){
   bool again=true;
   while (again==true){
   bool arg=valid_dimensions(argv[1], argv[2]);
   int rows, cols;
   m_d_values **table;
   while(arg==false){	               
      cout<<"Invalid dimensions."<<endl;		               
      cout<<"Enter Rows: ";			               
      cin>>argv[1];				               
      cout<<"Enter Cols: ";
      cin>>argv[2];
      arg=valid_dimensions(argv[1], argv[2]);
   }
   rows=atoi(argv[1]);
   cols=atoi(argv[2]);
   cout << rows << "," << cols << endl;
   table=create_table(rows,cols); 
cout << "Table made" << endl;   
   set_mult_values(table,rows,cols);			           
   set_div_values(table,rows,cols);				       
   print_tables(table,rows,cols);				           
   delete_table(table, rows);
   again=recalc(argv);
   }   
   return 0;
}


bool recalc(char *argv[]){
   int choice;
   cout << "continue (1) quit (2)";
   cin >> choice;
   if (choice == 1){
      cout << "how many rows: ";
      cin >> argv[1];
      cout << "how many cols: ";
      cin >> argv[2];
   }
   else exit(1);
   return true;
}

bool valid_dimensions(char *m, char *n){
   if(m[0]==48){
      return false;
   }
   else if(n[0]==48){
       return false;
   }
   for(int i=0; m[i]!='\0'; i++){
      if (m[i]<48 || m[i]>57) return false;
   }
   return true;
}

m_d_values **create_table(int m, int n){
    m_d_values **table;
    table=new m_d_values *[m];
    for(int i=0; i<m; i++){
            table[i]=new m_d_values [n];
        }
    return table;
}

void set_mult_values(m_d_values **table, int m, int n){
  /* for(int i=0; i<m; i++){
      table[i][0].mult=i+1;
   }
   for(int j=0; j<n; j++){
      table[0][j].mult=j+1;
   }
   for(int i=1; i<m; i++){
      for(int j=1; j<n; j++){
	 table[i][j].mult=table[i-1][j].mult*table[i][0].mult;
      }   
   }
   */

   for (int i=0; i< m; i++){
      table[i][0].mult=i+1;
   }
   for (int i=0; i<n; i++){
      table[0][i].mult=i+1;
   }
   for (int i=1; i<m; i++){
      for (int j=1; j<n; j++){
         table[i][j].mult = table[0][j].mult*table[i][0].mult;
      }
   }
   cout << "m vals set" << endl;
}

void set_div_values(m_d_values **table, int m, int n){
    for(int i=0; i<m; i++){
            table[i][0].div=i+1;
        }
    for(int j=0; j<n; j++){
            table[0][j].div=j+1;
        }
    for(int i=1; i<m; i++){
       for(int j=1; j<n; j++){
	   table[i][j].div=table[0][j].div/table[i][0].div;	            
       }       
    }
}

void print_tables(m_d_values **table, int m, int n){
   for (int i=0; i<m; i++){
      for (int j=0; j<n; j++){
         cout << table[i][j].mult << " ";
      }
      cout << endl;
   }
   cout << endl;
   for (int i=0; i<m; i++){
      for (int j=0; j<n; j++){
         cout << table[i][j].div << " ";
      }
      cout << endl;
   }
   cout << endl;
}

void delete_table(m_d_values **table, int m){
    for(int i=0; i<m; i++){
            delete [] table[i];
        }
    delete [] table;
}

