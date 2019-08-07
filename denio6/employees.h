// File: employees.h
// Author: Joshua DeNio

//Description
//Specification for the Employees class

#ifndef _EMPLOYEES_H_
#define _EMPLOYEES_H_

#include "employee.h"
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Employees : public list<T>
{
    public:
        // method - pushback
        // description - adds an employee to the list
        // preconditions - must have a valid object
        // postconditions -  adds a new employee to the list
        // method input - pointer to an Employee object
        // method output - none
        void pushback(const T&);
        
        // method - output
        // description - outputs to a file
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - none
        void output() const;
    private:
        list<T> empList;
};
#endif
