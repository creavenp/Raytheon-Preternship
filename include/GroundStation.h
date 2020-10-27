#ifndef SATELLITE_H
#define SATELLITE_H

class GroundStation : public Structure {

     public:

          // Constructor
          GroundStation(double x_in, double y_in, double z_in) :
                    Structure(x_in, y_in, z_in) {}

          // Destructor
          ~GroundStation() {}

};

#endif
