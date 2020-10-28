#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <iostream>

class Structure {

     private:

          // Coordinates of the structure
          // Relative to the center of the Earth
          double x;
          double y;
          double z;

     public:

          // Constructor
          Structure(double x_in, double y_in, double z_in) : x(x_in), y(y_in), z(z_in) {}

          // Virtual Destructor
          virtual ~Structure() {}

          double get_x() const {
               return x;
          }

          double get_y() const {
               return y;
          }

          double get_z() const {
               return z;
          }

          void set_coords(double x_in, double y_in, double z_in) {
               this -> x = x_in;
               this -> y = y_in;
               this -> z = z_in;
          }
};

#endif
