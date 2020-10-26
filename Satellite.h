#include <iostream>

class Satellite {

     private:

          // Coordinates of the satellite in outer space
          // Relative to the center of the Earth
          double x;
          double y;
          double z;

     public:

          Satellite(double x, double y, double z) : x(x), y(y), z(z) {}

          double get_x() {
               return x;
          }

          double get_y() {
               return y;
          }

          double get_z() {
               return z;
          }

          void set_coords(double x, double y, double z) {
               this -> x = x;
               this -> y = y;
               this -> z = z;
          }
};
