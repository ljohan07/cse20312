# This is the Makefile for the CSE 20312 course - Lecture 31

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


	
# Command: make TreapInsert
# Tests the Treap Insert Results
TreapInsertObjs := $(OBJ)/TreapInsert.o 

TreapInsert: $(TreapInsertObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/TreapInsert $(TreapInsertObjs)
	$(EXE)/./TreapInsert

$(OBJ)/TreapInsert.o: $(SRC)/TreapInsert.cpp $(INC)/Treap2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/TreapInsert.cpp -o $@


# Command: make InsertRandom
# Tests the Treap Insert Results
InsertRandomObjs := $(OBJ)/InsertRandom.o 

InsertRandom: $(InsertRandomObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/InsertRandom $(InsertRandomObjs)
	$(EXE)/./InsertRandom

$(OBJ)/InsertRandom.o: $(SRC)/InsertRandom.cpp $(INC)/Treap3.h
	$(PP) $(CXXFLAGS) -c $(SRC)/InsertRandom.cpp -o $@
	
	
# Command: make InsertRandom2
# Tests height for 100 versions of 100 inserts
InsertRandom2Objs := $(OBJ)/InsertRandom2.o 

InsertRandom2: $(InsertRandom2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/InsertRandom2 $(InsertRandom2Objs)
	$(EXE)/./InsertRandom2

$(OBJ)/InsertRandom2.o: $(SRC)/InsertRandom2.cpp $(INC)/Treap4.h
	$(PP) $(CXXFLAGS) -c $(SRC)/InsertRandom2.cpp -o $@
	
	
# Command: make TreapTest
# Tests the Treap Insert Results
TreapTestObjs := $(OBJ)/TreapTest.o 

TreapTest: $(TreapTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/TreapTest $(TreapTestObjs)
	$(EXE)/./TreapTest

$(OBJ)/TreapTest.o: $(SRC)/TreapTest.cpp $(INC)/Treap.h
	$(PP) $(CXXFLAGS) -c $(SRC)/TreapTest.cpp -o $@


# Initialize 
initialize:
	mkdir $(OBJ) $(EXE)

# Make all
all: SubsetSums BloomURL

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
