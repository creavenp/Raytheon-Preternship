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


# Command: make SatTest
# Initial Examples of Vertex
SatTestObjs := $(OBJ)/SatTest.o

SatTest: $(SatTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SatTest $(SatTestObjs)
	$(EXE)/./SatTest

$(OBJ)/SatTest.o: $(SRC)/SatTest.cpp $(INC)/Structure.h $(INC)/Satellite.h
	$(PP) $(CXXFLAGS) -c $(SRC)/SatTest.cpp -o $@

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize:
	mkdir obj exe


# Make all
all: Satellite


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
