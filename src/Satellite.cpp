#include "../include/Satellite.h"

int main() {

     // Test 1
     Satellite sat_1(44.3, 910.2, 23420.1);

     std::cout << "X location: " << sat_1.get_x() << std::endl;
     std::cout << "Y location: " << sat_1.get_y() << std::endl;
     std::cout << "Z location: " << sat_1.get_z() << std::endl;
     return 0;
}
