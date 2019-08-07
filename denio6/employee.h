// File: employee.h
// Author: Joshua DeNio

//Description
//Specification for the employee class

#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "person.h"
#include <iostream>
#include <fstream>

using namespace std;


class Employee : public Person {
    public:
        // method - getID
        // description - getter for ID
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - int
        int getID() const;
        
        // method - setID
        // description - setter for ID
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - String
        // method output - none
        void setID(const int&);
        
        // method - outputPayroll
        // description - outputs payroll info
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - ofstream
        virtual ofstream& output(ofstream&) const = 0;
    private:
        int employeeId;
};



#endif
