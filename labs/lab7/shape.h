#ifndef SHAPE_H
#define SHAPE_H
#include <string>
//#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
class shape{
   protected:
      string name;
      string color;
      double area;
   public:
      shape();
      virtual void calc_area()=0;
      virtual void print()=0;
      void print_shape_info(shape &);
};
#endif
