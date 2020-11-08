#include "../include/Project.h"

enum sat_id {sat1, sat2, sat3, sat4};

int c = 300000000;

double calculate_distance(Satellite satellite_1, Satellite satellite_2) {
     double x_diff = satellite_1.get_x() - satellite_2.get_x();
     double y_diff = satellite_1.get_y() - satellite_2.get_y();
     double z_diff = satellite_1.get_z() - satellite_2.get_z();
     double sum = pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2);
     return sqrt(sum);
}

int main() {
     Graph_Sat constellation;

     // Instantiate Satellites
     /*Satellite sat_1(1, 4, 3);
     Satellite sat_2(1.5, 7, 3.3);
     Satellite sat_3(5.4, 2.2, 2.9);
     Satellite sat_4(9.3, 1.1, 0.2);

     // Add satellites to the constellation
     constellation.add_vertex(sat_1);
     constellation.add_vertex(sat_2);
     constellation.add_vertex(sat_3);
     constellation.add_vertex(sat_4);

     // Add distances (edges)
     constellation.add_edge(sat1, sat2, calculate_distance(sat_1, sat_2));
     constellation.add_edge(sat1, sat3, calculate_distance(sat_1, sat_3));
     constellation.add_edge(sat1, sat4, calculate_distance(sat_1, sat_4));
     constellation.add_edge(sat3, sat2, calculate_distance(sat_3, sat_2));
     constellation.add_edge(sat3, sat4, calculate_distance(sat_3, sat_4));
     constellation.add_edge(sat2, sat4, calculate_distance(sat_3, sat_4));

     // Instantiate Ground Stations
     GroundStation gs_1(0, 0.5, 3);
     GroundStation gs_2(-3.1, 1.1, 0);

     // Updates the first satellite's location
	 for (int i = 0; i < 10; ++i) {
          std::cout << "\033[2J\033[1;1H";
          std::cout << constellation << std::endl;
          double curr_x = constellation.get_satellite_x(sat1) + pow(2, cos(constellation.get_satellite_x(sat1))); // example function
          constellation.set_satellite_x(sat1, curr_x);
          usleep(1000000);
     }*/

     Satellite sat_1(5, 5, 2);
     Satellite sat_2(1, 4, 4);
	 Satellite sat_3(5, 2, 3);

     constellation.add_vertex(sat_1);
     constellation.add_vertex(sat_2);
	 constellation.add_vertex(sat_3);

     constellation.add_edge(sat1 ,sat2, calculate_distance(sat_1, sat_2));
	constellation.add_edge(sat1, sat3, calculate_distance(sat_1, sat_3));
	constellation.add_edge(sat2, sat3, calculate_distance(sat_2, sat_3));

     time_t past, present;

     for (double t = 0; t < 6 * M_PI; t += 0.05) { // Three revolutions

          time(&past);
          sleep(1);
          time(&present);
          if (difftime(present, past) == 1) {
               std::cout << "\033[2J\033[1;1H";
               std::cout << constellation << std::endl << std::endl;

               constellation.set_edge_value(sat1, sat2, calculate_distance(constellation.get_vertex(sat1), constellation.get_vertex(sat2)));
     		constellation.set_edge_value(sat1, sat3, calculate_distance(constellation.get_vertex(sat1), constellation.get_vertex(sat3)));
     		constellation.set_edge_value(sat2, sat3, calculate_distance(constellation.get_vertex(sat2), constellation.get_vertex(sat3)));
               //constellation.Dijkstra(sat2);

               // Satellite 1 location
               constellation.set_satellite_x(sat1, sqrt(50) * cos(t));
               constellation.set_satellite_y(sat1, sqrt(50) * sin(t));
               constellation.set_satellite_z(sat1, cos(t) * 2 * sqrt(2));

               // Satelllite 2 location
               constellation.set_satellite_x(sat2, sqrt(17) * cos(t));
               constellation.set_satellite_y(sat2, sqrt(17) * sin(t));
               constellation.set_satellite_z(sat2, 4 * sqrt(17) * cos(t));

     		// Satellite 3 location
     		constellation.set_satellite_x(sat3, sqrt(29) * cos(t));
     		constellation.set_satellite_y(sat3, sqrt(29) * sin(t));
     	     constellation.set_satellite_z(sat3, sqrt(29) * 3 / 5 * cos(t));
          }
     }

}
