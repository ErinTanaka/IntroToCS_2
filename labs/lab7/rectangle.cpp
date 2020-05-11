#include "rectangle.h"
rectangle::rectangle(){
   name="rectangle";
   color="purple";
   length=2;
   width=3;
}
void rectangle::calc_area(){
   double area;
   area=length*width;
   cout <<"rectangle area is  " << area << endl;
}
void rectangle::print(){
   cout << "Shape " << name << endl; 
   cout << "length " << length << endl;
   cout << "width " << width << endl;
   cout << "Color " << color << endl;
}
