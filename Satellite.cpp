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

          double set_coords(double x, double y, double z) {
               this -> x = x;
               this -> y = y;
               this -> z = z;
          }
};

int main() {

     // Test 1
     Satellite sat_1(44.3, 910.2, 23420.1);

     std::cout << "X location: " << sat_1.get_x() << std::endl;
     std::cout << "Y location: " << sat_1.get_y() << std::endl;
     std::cout << "Z location: " << sat_1.get_z() << std::endl;     
     return 0;
}
