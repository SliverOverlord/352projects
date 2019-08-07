# File: makefile
# Author: Joshua DeNio


# Description
#This makefile will make the executable for prog7.

CC=g++
OBJECTS=main.o symbol.o hashfunctions.o 
EXE=prog7
CFLAGS=-fno-diagnostics-color -Wall
LFLAGS=

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
main.o:	main.cpp symbol.h hashtable.h hashlist.h
	$(CC) $(CFLAGS) -c main.cpp
symbol.o:	symbol.cpp symbol.h
	$(CC) $(CFLAGS) -c symbol.cpp

hashfunctions.o:	hashfunctions.cpp symbol.h
	$(CC) $(CFLAGS) -c hashfunctions.cpp


clean: 
	rm -rf prog7 *~ $(OBJECTS) $(EXE)
