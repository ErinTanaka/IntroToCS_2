#include <cstdlib>
#include <string>
#include "circle.h"
#include "rectangle.h"

using namespace std;

int main(){
   shape ** list;
   list=new shape*[3];
   circle c;
   rectangle r;
   circle p;
   list[0]=&c;
   list[1]=&r;
   list[2]=&p;
   for (int i=0; i<3; i++){
      list[i]->print();
   }
   return 0;
}
