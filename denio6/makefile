# File: makefile
# Author: Joshua DeNio


# Description
#This makefile will make the executable for the graph class

CC=g++
OBJECTS=main.o person.o date.o employee.o salaryEmployee.o hourlyEmployee.o employees.o read.o
EXE=prog6
CFLAGS=-fno-diagnostics-color -Wall
LFLAGS=

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
main.o:	main.cpp person.h date.h employee.h salaryEmployee.h hourlyEmployee.o employees.o
	$(CC) $(CFLAGS) -c main.cpp
person.o:	person.cpp person.h
	$(CC) $(CFLAGS) -c person.cpp
date.o:	date.cpp date.h
	$(CC) $(CFLAGS) -c date.cpp

employee.o:	employee.cpp employee.h
	$(CC) $(CFLAGS) -c employee.cpp
	
employees.o:	employees.cpp employees.h
	$(CC) $(CFLAGS) -c employees.cpp
	
hourlyEmployee.o:	hourlyEmployee.cpp hourlyEmployee.h
	$(CC) $(CFLAGS) -c hourlyEmployee.cpp
	
salaryEmployee.o:	salaryEmployee.cpp salaryEmployee.h
	$(CC) $(CFLAGS) -c salaryEmployee.cpp
	
read.o:		read.cpp
		$(CC) $(CFLAGS) -c read.cpp

clean: 
	rm -rf prog6 *~ $(OBJECTS) $(EXE)
