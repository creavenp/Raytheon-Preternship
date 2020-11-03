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

		void set_x(double x_in) {
  	          this -> x = x_in;
		}

		void set_y(double y_in) {
		  	this -> y = y_in;
	     }

		void set_z(double z_in) {
		  	this -> z = z_in;
		}

          void set_coords(double x_in, double y_in, double z_in) {
               this -> x = x_in;
               this -> y = y_in;
               this -> z = z_in;
          }

		// Overloaded << operator
		friend std::ostream& operator<<(std::ostream& output, const Structure& theStructure){
		     output << "Structure at (" << theStructure.get_x() << ", " << theStructure.get_y() << ", " << theStructure.get_z() << ")";
			return output;
		}
};

#endif
