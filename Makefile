# This is the Makefile for the CSE 20312 Raytheon Preternship

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -pthread
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj

# Command: make Project
ProjectObjs := $(OBJ)/Project.o

Project: $(ProjectObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Project $(ProjectObjs)
	$(EXE)/./Project

$(OBJ)/Project.o: $(SRC)/Project.cpp $(INC)/Project.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Project.cpp -o $@


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize:
	mkdir obj exe


# Make all
all: Project


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
