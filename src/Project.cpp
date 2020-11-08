#include "../include/Project.h"

enum sat_id {sat1, sat2, sat3, sat4};

#define c 300000000

double calculate_distance(Structure struct_1, Structure struct_2) {
     double x_diff = struct_1.get_x() - struct_2.get_x();
     double y_diff = struct_1.get_y() - struct_2.get_y();
     double z_diff = struct_1.get_z() - struct_2.get_z();
     double sum = pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2);
     return sqrt(sum);
}

void add_edges(Graph_Sat &constellation)
{
     // Add viable edges between satellites
     // Satellites can communicate with the one in front of it, behind it, above it, and below it
     for(int i = 0; i < 7; i ++)
     {
       // Horizontal links
      constellation.add_edge(i, i+1, calculate_distance(constellation.get_vertex(i), constellation.get_vertex(i+i)));
      constellation.add_edge(i+1, i, calculate_distance(constellation.get_vertex(i+1), constellation.get_vertex(i)));
      constellation.add_edge(i+8, i+9, calculate_distance(constellation.get_vertex(i+8), constellation.get_vertex(i+9)));
      constellation.add_edge(i+9, i+8, calculate_distance(constellation.get_vertex(i+9), constellation.get_vertex(i+8)));
      constellation.add_edge(i+16, i+17, calculate_distance(constellation.get_vertex(i+16), constellation.get_vertex(i+17)));
      constellation.add_edge(i+17, i+16, calculate_distance(constellation.get_vertex(i+17), constellation.get_vertex(i+16)));
      // Vertical links
      constellation.add_edge(i+8, i, calculate_distance(constellation.get_vertex(i+8), constellation.get_vertex(i)));
      constellation.add_edge(i, i+8, calculate_distance(constellation.get_vertex(i), constellation.get_vertex(i+8)));
      constellation.add_edge(i+8, i+16, calculate_distance(constellation.get_vertex(i+8), constellation.get_vertex(i+16)));
      constellation.add_edge(i+16, i+8, calculate_distance(constellation.get_vertex(i+16), constellation.get_vertex(i+8)));
     }
     // Final horizonal and vertical links (back to front, front to back)
     constellation.add_edge(0, 7, calculate_distance(constellation.get_vertex(0), constellation.get_vertex(7)));
     constellation.add_edge(7, 0, calculate_distance(constellation.get_vertex(7), constellation.get_vertex(0)));
     constellation.add_edge(8, 15, calculate_distance(constellation.get_vertex(8), constellation.get_vertex(15)));
     constellation.add_edge(15, 8, calculate_distance(constellation.get_vertex(15), constellation.get_vertex(8)));
     constellation.add_edge(16, 23, calculate_distance(constellation.get_vertex(16), constellation.get_vertex(23)));
     constellation.add_edge(23, 16, calculate_distance(constellation.get_vertex(23), constellation.get_vertex(16)));
     constellation.add_edge(7, 15, calculate_distance(constellation.get_vertex(7), constellation.get_vertex(15)));
     constellation.add_edge(15, 7, calculate_distance(constellation.get_vertex(15), constellation.get_vertex(7)));
     constellation.add_edge(15, 23, calculate_distance(constellation.get_vertex(15), constellation.get_vertex(23)));
     constellation.add_edge(23, 15, calculate_distance(constellation.get_vertex(23), constellation.get_vertex(15)));
}

void update_edges(Graph_Sat &constellation)
{
     // Update all edges between satellites
     for(int i = 0; i < 7; i ++)
     {
       // Horizontal links
      constellation.set_edge_value(i, i+1, calculate_distance(constellation.get_vertex(i), constellation.get_vertex(i+i)));
      constellation.set_edge_value(i+1, i, calculate_distance(constellation.get_vertex(i+1), constellation.get_vertex(i)));
      constellation.set_edge_value(i+8, i+9, calculate_distance(constellation.get_vertex(i+8), constellation.get_vertex(i+9)));
      constellation.set_edge_value(i+9, i+8, calculate_distance(constellation.get_vertex(i+9), constellation.get_vertex(i+8)));
      constellation.set_edge_value(i+16, i+17, calculate_distance(constellation.get_vertex(i+16), constellation.get_vertex(i+17)));
      constellation.set_edge_value(i+17, i+16, calculate_distance(constellation.get_vertex(i+17), constellation.get_vertex(i+16)));
      // Vertical links
      constellation.set_edge_value(i+8, i, calculate_distance(constellation.get_vertex(i+8), constellation.get_vertex(i)));
      constellation.set_edge_value(i, i+8, calculate_distance(constellation.get_vertex(i), constellation.get_vertex(i+8)));
      constellation.set_edge_value(i+8, i+16, calculate_distance(constellation.get_vertex(i+8), constellation.get_vertex(i+16)));
      constellation.set_edge_value(i+16, i+8, calculate_distance(constellation.get_vertex(i+16), constellation.get_vertex(i+8)));
     }
     // Final horizonal and vertical links (back to front, front to back)
     constellation.set_edge_value(0, 7, calculate_distance(constellation.get_vertex(0), constellation.get_vertex(7)));
     constellation.set_edge_value(7, 0, calculate_distance(constellation.get_vertex(7), constellation.get_vertex(0)));
     constellation.set_edge_value(8, 15, calculate_distance(constellation.get_vertex(8), constellation.get_vertex(15)));
     constellation.set_edge_value(15, 8, calculate_distance(constellation.get_vertex(15), constellation.get_vertex(8)));
     constellation.set_edge_value(16, 23, calculate_distance(constellation.get_vertex(16), constellation.get_vertex(23)));
     constellation.set_edge_value(23, 16, calculate_distance(constellation.get_vertex(23), constellation.get_vertex(16)));
     constellation.set_edge_value(7, 15, calculate_distance(constellation.get_vertex(7), constellation.get_vertex(15)));
     constellation.set_edge_value(15, 7, calculate_distance(constellation.get_vertex(15), constellation.get_vertex(7)));
     constellation.set_edge_value(15, 23, calculate_distance(constellation.get_vertex(15), constellation.get_vertex(23)));
     constellation.set_edge_value(23, 15, calculate_distance(constellation.get_vertex(23), constellation.get_vertex(15)));
}

int main() {
     Graph_Sat constellation;

	// Create satellites
  double x,y,z;
	for(int i = 0; i < 360; i+= 45)
	{
		// Satellites at latitude 30 degrees, altitude of 500 km, spaced 45 degrees from each other
		x = round(5961*cos(i*M_PI/180));
		y = round(5961*sin(i*M_PI/180));
		z = 3420;
		Satellite sat_1(x,y,z);
		constellation.add_vertex(sat_1);
	}
	for(int i = 0; i < 360; i += 45)
	{
	 	// Equator Satellites, altitude of 500 km, spaced 45 degrees from each other
	 	x = round(6878*cos(i*M_PI/180));
		y = round(6878*sin(i*M_PI/180));
		z = 0;
		Satellite sat_2(x,y,z);
		constellation.add_vertex(sat_2);
	}
	for(int i = 0; i < 360; i += 45)
  {
		// Satellites at latitude -30 degrees, altitude of 500 km, spaced 45 degrees from each other
		x = round(5961*cos(i*M_PI/180));
		y = round(5961*sin(i*M_PI/180));
		z = -3420;
		Satellite sat_3(x,y,z);
		constellation.add_vertex(sat_3);
	 }

   add_edges(constellation);

     time_t past, present;

     for (double t = 0; t < 6 * M_PI; t += 0.05) { // Three revolutions

          time(&past);
          sleep(1);
          time(&present);
          if (difftime(present, past) == 1) {
               std::cout << "\033[2J\033[1;1H";
               std::cout << constellation << std::endl << std::endl;

               // Orbit Calculations Here
               // *
               // *
               // *
               // *

               update_edges(constellation);
          }
     }

}
