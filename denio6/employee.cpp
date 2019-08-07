// File:    employee.cpp
// Author:  Joshua DeNio

// Description:
// This file contains the implimentation for the Employee class

#include "employee.h"

//getID
int Employee::getID() const
{
    return employeeId;
}

//setID
void Employee::setID(const int& tmpID)
{
    employeeId = tmpID;
}
