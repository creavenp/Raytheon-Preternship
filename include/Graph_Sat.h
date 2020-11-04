#ifndef GRAPH_SAT_H
#define GRAPH_SAT_H

#include "Vertex.h"
#include "DynArr.h"
#include "Stack.h"
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

          Satellite get_vertex(unsigned int vertex) {
               return vertices[vertex].get_vertex_value();
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
               // We will prevent this return from ever happening
               return -1;
          }

          double get_satellite_y(unsigned int vertex) {
               double y;
               if (vertex < vertices.length()) {
                    y = vertices[vertex].get_vertex_value().get_y();
                    return y;
               }
               // We will prevent this return from ever happening
               return -1;
          }

          double get_satellite_z(unsigned int vertex) {
               double z;
               if (vertex < vertices.length()) {
                    z = vertices[vertex].get_vertex_value().get_z();
                    return z;
               }
               // We will prevent this return from ever happening
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

          void set_edge_value(unsigned int origin, unsigned int destin, double weight) {
               if (origin < vertices.length() && destin < vertices.length()) {
                    vertices[origin].set_edge_value(destin, weight);
               }
          }

          // Dijkstra's Algorithm
		void Dijkstra( unsigned int destin ){


			if( destin >= vertices.length() || vertices.length() == 0 ){

				std::cout << "Invalid Inputs" << std::endl;
				return;

			}

			/* Initialize the Elements */
			Stack< unsigned int > theStack;
			DynArr< unsigned int > parents( vertices.length() );
			DynArr< double > distance;
			Stack< unsigned int > finalPath;

			bool found = false;

			/* Initialize the origin */
			theStack.push( 0 );
			distance[0] = 0;
			parents[0] = 2147483647;

			if( destin == 0 ){
				found = true;
			}

			if( !found ){

				/* Initialize all the distances after the origin */
				for( unsigned int iter = 1; iter < vertices.length(); iter++ ){
					// Make it the largest possible int
					distance[ iter ] = 2147483647;
					// Set the parent to -1
					parents[ iter ] = 2147483647;
				}

				/* Run the shortest path algorithm */
				while( !theStack.empty() ){

					// Get the top element of the stack and pop
					unsigned int index = theStack.top();
					theStack.pop();

					// Evaluate the edges from the vertex
					for(unsigned int iter = 0; iter < vertices[ index ].num_edges(); iter++ ){

						// Obtain the edge
						Edge tempEdge = vertices[ index ].get_edge( iter );

						// If the weight of the edge plus distance of the  distance is less than the destin weight
						if( distance[ index ] + tempEdge.weight < distance[ tempEdge.destin ] ) {

							// Update the distance
							distance[ tempEdge.destin ] = distance[ index ] + tempEdge.weight;

							// Update the parent of the destin
							parents[ tempEdge.destin ] = index;

							// Check if destin is the result;
							if( tempEdge.destin == destin && !found ){

								found = true;
							}

							theStack.push( tempEdge.destin );
						}
					}
				}
			}

			// Otherwise, go through the parents until we find the origin
			if( found ){

				unsigned int sentinel = destin;
				finalPath.push( sentinel );		// Push the desination onto the stack

				while( parents[sentinel] != 2147483647 ){

					finalPath.push( parents[sentinel] );	// Push the parent onto the stack
					sentinel = parents[sentinel];			// Update the sentinel

				}

				// Stack contains the correct order
                    std::cout << "A valid path exists between sat1 to sat" << destin + 1 << " : ";
				while( !finalPath.empty() ){

					std::cout << finalPath.top() + 1;
                         if (finalPath.size() > 1) {
                              std::cout << " -> ";
                         }
					finalPath.pop();
				}
				std::cout << std::endl << "Distance: "<< distance[destin] << std::endl;
				std::cout << std::endl;
			}

		}

          // Overloaded operator
          friend std::ostream& operator<<(std::ostream& output, const Graph_Sat& theGraph) {
               for (unsigned int i = 0; i < theGraph.vertices.length(); ++i) {
                    output << i << ": " << theGraph.vertices[i] << std::endl;
               }
               return output;
          }

};

#endif
