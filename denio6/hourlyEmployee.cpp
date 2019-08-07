// File: hourlyEmployee.cpp
// Author: Joshua DeNio

//Description
//This file contains the implimentation for the HourlyEmployee class

#include "hourlyEmployee.h"


//constructor
HourlyEmployee::HourlyEmployee(string nameStr, Date bDay, string ssN, int id, int hours,int wage)
{
    this->setName(nameStr);
    this->setBDay(bDay);
    this->setSSN(ssN);
    this->setID(id);
    this->setHours(hours);
    this->setWage(wage);
}

//getHours
int HourlyEmployee::getHours() const
{
    return hours;
}

//getWage
double HourlyEmployee::getWage()const
{
    return wage;
}

//setHours
void HourlyEmployee::setHours(const int& tmpHours)
{
    hours = tmpHours;
}

//setWage
void HourlyEmployee::setWage(const double& tmpWage)
{
    wage = tmpWage;
}

//output
ofstream& HourlyEmployee::output(ofstream& oFile) const 
{
    oFile << fixed << showpoint << setprecision(2);
    oFile << setw(25) << getName();
    oFile << setw(10) << getBDay();
    oFile << setw(12) << getSSN();
    oFile << setw(7) << getID();
    oFile << setw(10) << getHours();
    oFile << setw(10) << getWage();
    oFile << "\n";
    return oFile;
}
