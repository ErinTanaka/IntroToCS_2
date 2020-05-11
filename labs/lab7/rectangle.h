#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
using namespace std;
class rectangle : public shape{
   private:
      double length;
      double width;
   public:
      rectangle();
      void calc_area();
      void print();
};
#endif
