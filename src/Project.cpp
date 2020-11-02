#include "../include/Project.h"

enum sat_id {sat1, sat2, sat3, sat4};

int c = 300000000;

double calculate_distance(Satellite sat1, Satellite sat2) {
     double x_diff = sat1.get_x() - sat2.get_x();
     double y_diff = sat1.get_y() - sat2.get_y();
     double z_diff = sat1.get_z() - sat2.get_z();
     double sum = pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2);
     return sqrt(sum);
}

int main() {
     Graph<Satellite> constellation;

     // Instantiate Satellites
     Satellite sat_1(1, 4, 3);
     Satellite sat_2(1.5, 7, 3.3);
     Satellite sat_3(5.4, 2.2, 2.9);

     // Add satellites to the constellation
     constellation.add_vertex(sat_1);
     constellation.add_vertex(sat_2);
     constellation.add_vertex(sat_3);

     // Add distances (edges)
     constellation.add_edge(sat1, sat2, calculate_distance(sat_1, sat_2));
     constellation.add_edge(sat1, sat3, calculate_distance(sat_1, sat_3));

     std::cout << constellation << std::endl;

}
