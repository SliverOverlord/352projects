// File: hourlyEmployee.h
// Author: Joshua DeNio

//Description
//Specification for the HourlyEmployee class

#ifndef _HOURLY_EMPLOYEE_H_
#define _HOURLY_EMPLOYEE_H_

#include "employee.h"
#include <iomanip>

using namespace std;


class HourlyEmployee : public Employee {
    public:
        // method - constructor
        // description - constructor
        // preconditions - must have valid input
        // postconditions -  makes an object
        // method input - string,Date,string,int,itn
        // method output - none
        HourlyEmployee(string nameStr, Date bDay, string ssN, int id, int hours,int wage);
        
        // method - getHours
        // description - getter for hours
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - int
        int getHours() const;
        
        // method - getWage
        // description - getter for wage
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - double
        double getWage()const;
        
        // method - setHours
        // description - setter for hours
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - int
        // method output - none
        void setHours(const int&);
        
        // method - setWage
        // description - setter for wage
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - double
        // method output - none
        void setWage(const double&);
        
        // method - outputPayroll
        // description - outputs payroll info
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - ofstream
        ofstream& output(ofstream&) const;
        
    private:
        int hours;
        double wage;
};
#endif
