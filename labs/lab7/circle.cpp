#include "circle.h"

circle::circle(){
   name="circle";
   color="blue";
   radius=5;
}
void circle:: set_radius(double r){
   radius=r;
}
double circle::get_radius(){
   return radius;
}
void circle::calc_area(){
   double area;
   area=3.14*25;
   cout << "Area of circle is" << area << endl;
}
void circle::print(){
   cout << "Shape " << name << endl;
   cout << "Radius " << radius << endl;
   cout << "color " << color << endl;
}
