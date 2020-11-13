#include "../include/Project.h"
#include <atomic>
std::atomic<bool> stop;


enum sat_id {sat1, sat2, sat3, sat4, sat5, sat6, sat7, sat8,
             sat9, sat10, sat11, sat12, sat13, sat14, sat15, sat16,
             sat17, sat18, sat19, sat20, sat21, sat22, sat23, sat24};

#define SPEED_OF_LIGHT 300000000

double calculate_distance(Structure struct1, Structure struct2) {
     double x_diff = struct1.get_x() - struct2.get_x();
     double y_diff = struct1.get_y() - struct2.get_y();
     double z_diff = struct1.get_z() - struct2.get_z();
     double sum = pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2);
     double dist = sqrt(sum);
     return dist;
}

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

void runOrbits(Graph_Sat constellation) {
  double t = 0;
  while (1) {
      if(!(stop)) {
        usleep(100000);
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Press Space determine latency between ground stations:" << std::endl << std::endl;
        std::cout << constellation << std::endl;
        orbit(t, constellation);
        constellation.update_edges();
        t += 0.01;
      }
 }
}

int main() {
      Graph_Sat constellation;

      stop = false;
      char c;

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
       GroundStation gs_2(-2500, 2300, 3000);

       DynArr<GroundStation> stations(0);
       stations.push_back(gs_1);
       stations.push_back(gs_2);


       // Sets satellites in motion for one orbit and displays location data

      // Once paused
      bool exit = false;
      std::thread oThread(runOrbits, constellation);
      while (!exit) {
           int choice;
           /*std::cout << "-------------------------------------------------------------------------" << std::endl;
           std::cout << "Running Orbits ..." << std::endl;
           //std::thread oThread(runOrbits, constellation);
           std::cout << "Press Enter to Stop Orbits" << std::endl;*/
           fflush(stdin);
           std::cin.get(c);
           /*while(c != 'a') {
             std::cin >> c;
           }*/
           stop = true;
           usleep(100000);
           //oThread.join();
           std::cout << std::endl << "Menu: " << std::endl << std::endl;
           std::cout << "1: Continue Simulation" << std::endl;
           std::cout << "2: Add Ground Station" << std::endl;
           std::cout << "3: Determine smallest latency path between ground stations" << std::endl;
           std::cout << "4: Exit program" << std::endl;
           std::cin >> choice;

           if (choice == 1) {
                // continue simulation
                stop = false;
           }

           else if (choice == 2) {
                // Add Ground Station
                std::cout << std::endl;
                double x, y, z;
                std::cout << "Enter the xyz values of the new ground station: " << std::endl << std::endl;
                std::cout << "x: ";
                std::cin >> x;
                std::cout << std::endl << "y: ";
                std::cin >> y;
                std::cout << std::endl << "z: ";
                std::cin >> z;
                GroundStation new_gs(x, y, z);
                stations.push_back(new_gs);
                std::cout << std::endl << "New groundstation added" << std::endl << "Press enter to continue" << std::endl;
           }

           else if (choice == 3) {
                // Determine smallest latency path between ground stations
                std::cout << std::endl;
                for (unsigned int i = 0; i < stations.length(); ++i) {
                     std::cout << "(GS" << i + 1 << ")  ";
                     std::cout << "x: " << stations[i].get_x() << " km  ";
                     std::cout << "y: " << stations[i].get_y() << " km  ";
                     std::cout << "z: " << stations[i].get_z() << " km  ";
                     std::cout << std::endl;
                }

                unsigned int select_1, select_2;
                std::cout << std::endl << "What ground stations would you like to connect? ";
                std::cout << "Ground Station (origin): ";
                std::cin >> select_1;
                std::cout << "Ground Station (destination): ";
                std::cin >> select_2;
                std::cout << std::endl;

                // Find satellite that is the closest to each ground station
                double smallest_dist_1 = DBL_MAX;
                double smallest_dist_2 = DBL_MAX;
                unsigned int closest_sat_1;
                unsigned int closest_sat_2;
                for (unsigned int i = 0; i < constellation.get_vertices().length(); ++i) {
                     double current_dist_1 = calculate_distance(constellation.get_vertex(i), stations[select_1 - 1]);
                     double current_dist_2 = calculate_distance(constellation.get_vertex(i), stations[select_2 - 1]);
                     if (current_dist_1 < smallest_dist_1) {
                          smallest_dist_1 = current_dist_1;
                          closest_sat_1 = i;
                     }
                     if (current_dist_2 < smallest_dist_2) {
                          smallest_dist_2 = current_dist_2;
                          closest_sat_2 = i;
                     }
                }

                // Run Dijkstra's Algorithm
                Stack<unsigned int> finalPath;
                std::cout << closest_sat_1 << std::endl;
                std::cout << closest_sat_2 << std::endl;
                constellation.Dijkstra(closest_sat_1, closest_sat_2, finalPath);
                std::cout << "Shortest Path: ";
                std::cout << "(GS" << select_1 << ") --> ";
                for (unsigned int i = 0; i < finalPath.size(); ++i) {
                     std::cout << "Sat(" << finalPath.top() << ") --> ";
                     finalPath.pop();
                }
                std::cout << "(GS" << select_2 << ")";
                std::cout << std::endl << "Press enter to contine" << std::endl;


           }

           else {
                exit = true;
           }
      }
      std::cout << "\033[2J\033[1;1H";
}
