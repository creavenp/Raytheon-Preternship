#include "../include/Project.h"

enum sat_id {sat1, sat2, sat3, sat4, sat5, sat6, sat7, sat8,
             sat9, sat10, sat11, sat12, sat13, sat14, sat15, sat16,
             sat17, sat18, sat19, sat20, sat21, sat22, sat23, sat24};

#define SPEED_OF_LIGHT 300000000

void add_edges(Graph_Sat& constellation)
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


// Simulate small differences in the orbital pattern of the first num structures
// Adds a random value between +/-50 to show the distance recalculations
void add_noise(unsigned int num, Graph_Sat& constellation)
{
    for(unsigned int i = 0; i < num; ++i)
  	{
    	     double new_x = constellation.get_satellite_x(i) + (rand()%100-50);
    	     double new_y = constellation.get_satellite_y(i) + (rand()%100-50);
    	     double new_z = constellation.get_satellite_z(i) + (rand()%100-50);
		constellation.set_satellite_xyz(i, new_x, new_y, new_z);
  	}
}

void orbit(double t, Graph_Sat& constellation) {

      // Satellites at latitude 30 degrees, altitude of 500 km from sea level, spaced 45 degrees from each other
	 for(unsigned int i = sat1; i <= sat8; ++i)
	 {
		constellation.set_satellite_xyz(i, cos(t+M_PI*i/4) * 5961, sin(t+M_PI*i/4) * 5961, 3240);
	 }

	 // Satellites above the equator, altitude of 500 km from sea level, spaced 45 degrees from each other
	 for(unsigned int i = sat9; i <= sat16; ++i)
	 {
		constellation.set_satellite_xyz(i, cos(t+M_PI*i/4) * 6878, sin(t+M_PI*i/4) * 6878, 0);
	 }

     // Satellites at latitude -30 degrees, altitude of 500 km from sea level, spaced 45 degrees from each other
	 for(unsigned int i = sat17; i <= sat24; ++i)
	 {
		constellation.set_satellite_xyz(i, cos(t+M_PI*i/4) * 5961, sin(t+M_PI*i/4) * 5961, -3240);
	 }

	 // Simulate small differences in orbital pattern by randomly moving the satellites
	 add_noise(24, constellation);
}

int main() {
      Graph_Sat constellation;

	  // Add 24 Satellites to the constellation
	  for(int i = 0; i < 24; ++i)
       {
            Satellite sat(0,0,0);
            constellation.add_vertex(sat);
       }

	  // Initialize the constellation orbits at t=0
       orbit(0, constellation);

	  // Add all intersatellite links to the constellation
       add_edges(constellation);

       // Create GroundStations
       GroundStation gs_1(2900, 2000, 1000);
       GroundStation gs_2(-2500, 2300, -700);

      // Create connections between Ground Stations and nearby Satellites
      

       // Sets satellites in motion for one orbit and displays location data
       /*for (double t = 0; t < 2 * M_PI; t += 0.01) {
           usleep(100000);
           std::cout << "\033[2J\033[1;1H";
           std::cout << "Press Space determine latency between ground stations:" << std::endl << std::endl;
           std::cout << constellation << std::endl;
           orbit(t, constellation);
           constellation.update_edges();
      }*/

      //onstellation.Dijkstra(sat2);
}
