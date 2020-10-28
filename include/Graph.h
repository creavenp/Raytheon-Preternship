#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include "DynArr.h"
#include <iostream>

template<class T>
class Graph{

	private:
		DynArr< Vertex< T > > vertices;	// Adjacency Lisy

	public:
		// Constructor
		Graph( ) : vertices() {}

		// Add a vertex prior to any edges
		void add_vertex( T vertexData ){

			Vertex<T> theVertex( vertexData );
			vertices.push_back( theVertex );
		}

		// Add Edge from Origin to Destination, with weight
		void add_edge(unsigned int origin, unsigned int destin, double weight ){
			if( origin < vertices.length() && destin < vertices.length() ){

				vertices[origin].add_edge( destin, weight );

			}
		}

		// Return the value with a Call by Reference
		// bool for if the vertex requested was valid
		bool get_vertex_value( unsigned int vertex, T& value ){

			if( vertex < vertices.length() ){

				value = vertices.at(vertex).get_vertex_value();
				return true;
			}

			return false;

		}

		// Set the value at a given vertex
		// bool for if the vertex requested was valid
		bool set_vertex_value( unsigned int vertex, T& value ){

			if( vertex < vertices.length() ){

				value = vertices[vertex].set_vertex_value( value );
				return true;
			}
			return false;
		}

		// Return the value with a Call by Reference
		// bool for if the origin and destination requested were valid
		bool get_edge_value( unsigned int origin, unsigned int destin, double& weight){

			if( origin < vertices.length() && destin < vertices.length() ){

				return vertices[origin].get_edge_value( destin, weight );
			}

			return false;
		}

		// Set the value at a given origin and destination
		// bool for if the origin and destination requested were valid
		bool set_edge_value( unsigned int origin, unsigned int destin, double weight){

			if( origin < vertices.length() && destin < vertices.length() ){

				return vertices[origin].set_edge_value( destin, weight );
			}

			return false;
		}

		// Overloaded Operator
		friend std::ostream& operator<<( std::ostream& output, const Graph<T>& theGraph ){

			for( unsigned int iter = 0; iter < theGraph.vertices.length(); iter++ ){

				output << iter << ": " << theGraph.vertices[ iter ] << std::endl;

			}

			return output;
		}
};

#endif
