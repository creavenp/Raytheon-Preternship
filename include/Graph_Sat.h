#ifndef GRAPH_SAT_H
#define GRAPH_SAT_H

#include "Vertex.h"
#include "DynArr.h"
#include <iostream>

class Graph_Sat {

     private:

          DynArr<Vertex<Satellite>> vertices; // Adjacency calculate_distance

     public:

          // Constructor
          Graph_Sat() : vertices() {}

          void add_vertex(Satellite vertexData) {
               Vertex<Satellite> theVertex(vertexData);
               vertices.push_back(theVertex);
          }

          // Add Edge from Origin to Destination, with weight
          void add_edge(unsigned int origin, unsigned int destin, double weight) {
               if (origin < vertices.length() && destin < vertices.length()) {
                    vertices[origin].add_edge(destin, weight);
               }
          }

          // Return x value of certain vertex
          double get_satellite_x(unsigned int vertex) {
               double x;
               if (vertex < vertices.length()) {
                    x = vertices[vertex].get_vertex_value().get_x();
                    return x;
               }
               return -1;
          }

          double get_satellite_y(unsigned int vertex) {
               double y;
               if (vertex < vertices.length()) {
                    y = vertices[vertex].get_vertex_value().get_y();
                    return y;
               }
               return -1;
          }

          double get_satellite_z(unsigned int vertex) {
               double z;
               if (vertex < vertices.length()) {
                    z = vertices[vertex].get_vertex_value().get_z();
                    return z;
               }
               return -1;
          }

          void set_satellite_x(unsigned int vertex, double x_in) {
               if (vertex < vertices.length()) {
                    vertices[vertex].get_vertex_value().set_x(x_in);
               }
          }

          void set_satellite_y(unsigned int vertex, double y_in) {
               if (vertex < vertices.length()) {
                    vertices[vertex].get_vertex_value().set_y(y_in);
               }
          }

          void set_satellite_z(unsigned int vertex, double z_in) {
               if (vertex < vertices.length()) {
                    vertices[vertex].get_vertex_value().set_z(z_in);
               }
          }

          // Add get and set edge functions theStructure

          // Overloaded operator
          friend std::ostream& operator<<(std::ostream& output, const Graph_Sat& theGraph) {
               for (unsigned int i = 0; i < theGraph.vertices.length(); ++i) {
                    output << i << ": " << theGraph.vertices[i] << std::endl;
               }
               return output;
          }

};

#endif
