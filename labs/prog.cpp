//#include <iostream>
//#include <string>
//#include <cstdlib>
#include "./mult_div.h"

//using namespace std;
  
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
	 arg=valid_dimensions(argv[1], argv[2])			      
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
		
