#include "lab6.h"
#include <iostream>
using namespace std;
test::test(){
   cout << "making a default test"<< endl;
   num=0;
   num_array=NULL;
}
test::test(int i){
   cout << "making a non default test" << endl;
   num=i;
   num_array= new int[i];
}
int test::get_num(){
   return num;
}
void test::set_num(int n){
   num=n;
}
