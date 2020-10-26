# This is the Makefile for the CSE 20312 Raytheon Preternship

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj


# Command: make Satellite
# Initial Examples of Vertex
SatelliteObjs := $(OBJ)/Satellite.o

Satellite: $(SatelliteObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Satellite $(SatelliteObjs)
	$(EXE)/./Satellite

$(OBJ)/Satellite.o: $(SRC)/Satellite.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Satellite.cpp -o $@


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize:
	mkdir obj exe


# Make all
all: Satellite


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
