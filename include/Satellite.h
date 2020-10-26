#ifndef SATELLITE_H
#define SATELLITE_H

#include <iostream>

class Satellite {

     private:

          // Coordinates of the satellite in outer space
          // Relative to the center of the Earth
          double x;
          double y;
          double z;

     public:

          Satellite(double x_in, double y_in, double z_in) : x(x_in), y(y_in), z(z_in) {}

          double get_x() {
               return x;
          }

          double get_y() {
               return y;
          }

          double get_z() {
               return z;
          }

          void set_coords(double x_in, double y_in, double z_in) {
               this -> x = x_in;
               this -> y = y_in;
               this -> z = z_in;
          }
};

#endif
