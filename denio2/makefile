# File: makefile
# Author: Joshua DeNio


# Description
#This makefile will make the executable for the Date class

CC=g++
OBJECTS=main.o date.o
EXE=prog2
CFLAGS=-fno-diagnostics-color -Wall
LFLAGS=

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
main.o:                 main.cpp date.h
	$(CC) $(CFLAGS) -c main.cpp
date.o:       date.cpp date.h
	$(CC) $(CFLAGS) -c date.cpp
clean:
	rm -rf prog2 *~ $(OBJECTS) $(EXE)
