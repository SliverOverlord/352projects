# File: makefile
# Author: Joshua DeNio


# Description
#This makefile will make the executable for the fraction class

CC=g++
OBJECTS=main.o fraction.o
EXE=prog
CFLAGS=-fno-diagnostics-color -Wall
LFLAGS=

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
main.o:                 main.cpp fraction.h
	$(CC) $(CFLAGS) -c main.cpp
fraction.o:       fraction.cpp fraction.h
	$(CC) $(CFLAGS) -c fraction.cpp
clean:
	rm -rf prog *~ $(OBJECTS) $(EXE)
