#include "lab6.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
   //off by one
   int myarray[5];
   cout << "what should print 0 1 2 3 4" << endl;
   for (int i=0; i<5; i++){
      myarray[i]=i;
   }
   cout << "off by one print" << endl;
   for (int i=1; i<5; i++){
      cout << myarray[i] << endl;
   }
   //initializing object different than one using
   /*   test a(5);

      test a.set_num(3);
   */
   //forget big three
   test a(5);
   //mem that hasn't been allocated
   int* num;
   num=NULL;

   cout << num[7] << endl;
   return 0;
}
