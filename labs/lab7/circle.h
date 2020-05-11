#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
using namespace std;
class circle : public shape{
   private:
      double radius;
   public:
      circle();
      void set_radius(double);
      double get_radius();
      void calc_area();
      void print();
};
#endif
