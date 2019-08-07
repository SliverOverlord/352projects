# File: makefile
# Author: Joshua DeNio


# Description
#This makefile will make the executable for the graph class

CC=g++
OBJECTS=main.o city.o
EXE=prog5
CFLAGS=-fno-diagnostics-color -Wall
LFLAGS=

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
main.o:	main.cpp graph.h city.h
	$(CC) $(CFLAGS) -c main.cpp
city.o:	city.cpp city.h
	$(CC) $(CFLAGS) -c city.cpp

clean: 
	rm -rf prog5 *~ $(OBJECTS) $(EXE)
