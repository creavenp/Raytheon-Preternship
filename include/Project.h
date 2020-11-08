#ifndef PROJECT_H
#define PROJECT_H

#include "../include/Structure.h"
#include "../include/Satellite.h"
#include "../include/GroundStation.h"
#include "../include/Graph_Sat.h"
#include <math.h>
#include <time.h>
#include <unistd.h>

double calculate_distance(Structure s1, Structure s2);
void add_edges(Graph_Sat &constellation);
void update_edges(Graph_Sat &constellation);

#endif
