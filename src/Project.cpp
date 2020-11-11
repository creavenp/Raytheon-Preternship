#include "../include/Project.h"

enum sat_id {sat1, sat2, sat3, sat4, sat5, sat6, sat7, sat8,
             sat9, sat10, sat11, sat12, sat13, sat14, sat15, sat16,
             sat17, sat18, sat19, sat20, sat21, sat22, sat23, sat24};

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
     for(unsigned int i = 0; i < 7; i ++)
     {
       // Horizontal links
      constellation.add_edge(i, i+1);
      constellation.add_edge(i+1, i);
      constellation.add_edge(i+8, i+9);
      constellation.add_edge(i+9, i+8);
      constellation.add_edge(i+16, i+17);
      constellation.add_edge(i+17, i+16);
      // Vertical links
      constellation.add_edge(i+8, i);
      constellation.add_edge(i, i+8);
      constellation.add_edge(i+8, i+16);
      constellation.add_edge(i+16, i+8);
     }
     // Final horizonal and vertical links (back to front, front to back)
     constellation.add_edge(0, 7);
     constellation.add_edge(7, 0);
     constellation.add_edge(8, 15);
     constellation.add_edge(15, 8);
     constellation.add_edge(16, 23);
     constellation.add_edge(23, 16);
     constellation.add_edge(7, 15);
     constellation.add_edge(15, 7);
     constellation.add_edge(15, 23);
     constellation.add_edge(23, 15);
}

void update_edges(Graph_Sat &constellation)
{
     // Update all edges between satellites
     for(unsigned int i = 0; i < 7; i ++)
     {
       // Horizontal links
      constellation.set_edge_value(i, i+1);
      constellation.set_edge_value(i+1, i);
      constellation.set_edge_value(i+8, i+9);
      constellation.set_edge_value(i+9, i+8);
      constellation.set_edge_value(i+16, i+17);
      constellation.set_edge_value(i+17, i+16);
      // Vertical links
      constellation.set_edge_value(i+8, i);
      constellation.set_edge_value(i, i+8);
      constellation.set_edge_value(i+8, i+16);
      constellation.set_edge_value(i+16, i+8);
     }
     // Final horizonal and vertical links (back to front, front to back)
     constellation.set_edge_value(0, 7);
     constellation.set_edge_value(7, 0);
     constellation.set_edge_value(8, 15);
     constellation.set_edge_value(15, 8);
     constellation.set_edge_value(16, 23);
     constellation.set_edge_value(23, 16);
     constellation.set_edge_value(7, 15);
     constellation.set_edge_value(15, 7);
     constellation.set_edge_value(15, 23);
     constellation.set_edge_value(23, 15);
}

void orbit(double t, Graph_Sat& constellation) {

     // z = 3420 km Satellites
     constellation.set_satellite_xyz(sat1, cos(t) * 5961, sin(t) * 5961, 3420);
     constellation.set_satellite_xyz(sat2, cos(t) * 5961, sin(t) * 5961, 3420);
     constellation.set_satellite_xyz(sat3, cos(t) * 5961, sin(t) * 5961, 3420);
     constellation.set_satellite_xyz(sat4, cos(t) * 5961, sin(t) * 5961, 3420);
     constellation.set_satellite_xyz(sat5, cos(t) * 5961, sin(t) * 5961, 3420);
     constellation.set_satellite_xyz(sat6, cos(t) * 5961, sin(t) * 5961, 3420);
     constellation.set_satellite_xyz(sat7, cos(t) * 5961, sin(t) * 5961, 3420);
     constellation.set_satellite_xyz(sat8, cos(t) * 5961, sin(t) * 5961, 3420);

     // z = 0 km Satellites
     constellation.set_satellite_xyz(sat9, cos(t) * 6878, sin(t) * 6878, 0);
     constellation.set_satellite_xyz(sat10, cos(t) * 6878, sin(t) * 6878, 0);
     constellation.set_satellite_xyz(sat11, cos(t) * 6878, sin(t) * 6878, 0);
     constellation.set_satellite_xyz(sat12, cos(t) * 6878, sin(t) * 6878, 0);
     constellation.set_satellite_xyz(sat13, cos(t) * 6878, sin(t) * 6878, 0);
     constellation.set_satellite_xyz(sat14, cos(t) * 6878, sin(t) * 6878, 0);
     constellation.set_satellite_xyz(sat15, cos(t) * 6878, sin(t) * 6878, 0);
     constellation.set_satellite_xyz(sat16, cos(t) * 6878, sin(t) * 6878, 0);

     // z = -3420 km Satellites
     constellation.set_satellite_xyz(sat17, cos(t) * 5961, sin(t) * 5961, -3420);
     constellation.set_satellite_xyz(sat18, cos(t) * 5961, sin(t) * 5961, -3420);
     constellation.set_satellite_xyz(sat19, cos(t) * 5961, sin(t) * 5961, -3420);
     constellation.set_satellite_xyz(sat20, cos(t) * 5961, sin(t) * 5961, -3420);
     constellation.set_satellite_xyz(sat21, cos(t) * 5961, sin(t) * 5961, -3420);
     constellation.set_satellite_xyz(sat22, cos(t) * 5961, sin(t) * 5961, -3420);
     constellation.set_satellite_xyz(sat23, cos(t) * 5961, sin(t) * 5961, -3420);
     constellation.set_satellite_xyz(sat24, cos(t) * 5961, sin(t) * 5961, -3420);
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

      for (double t = 0; t < 2 * M_PI; t += 0.01) { // One revolution
           usleep(100000);
           std::cout << "\033[2J\033[1;1H";
           std::cout << constellation << std::endl << std::endl;
           orbit(t, constellation);
           update_edges(constellation);
      }
}
