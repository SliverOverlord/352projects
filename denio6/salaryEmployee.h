// File: salaryEmployee.h
// Author: Joshua DeNio

//Description
//Specification for the SalaryEmployee class

#ifndef _SALARY_EMPLOYEE_H_
#define _SALARY_EMPLOYEE_H_

#include "employee.h"

using namespace std;


class SalaryEmployee : public Employee {
    public:
        
        // method - constructor
        // description - constructor
        // preconditions - must have valid input
        // postconditions -  makes an object
        // method input - string,Date,string,int,itn
        // method output - none
        SalaryEmployee(string nameStr, Date bDay, string ssN, int id,int sal);
        
        // method - getSalary
        // description - getter for salary
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - double
        double getSalary() const;
        
        // method - setSalary
        // description - setter for salary
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - double
        // method output - none
        void setSalary(const double&);
        
        // method - outputPayroll
        // description - outputs payroll info
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - ofstream
        ofstream& output(ofstream&) const;
        
    private:
        double salary;
};
#endif
