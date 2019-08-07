// File: salaryEmployee.cpp
// Author: Joshua DeNio

//Description
//Implimaentation for the SalaryEmployee class

#include "salaryEmployee.h"
#include <iomanip>

//constructor
SalaryEmployee::SalaryEmployee(string nameStr, Date bDay, string ssN, int id,int sal)
{
    this->setName(nameStr);
    this->setBDay(bDay);
    this->setSSN(ssN);
    this->setID(id);
    this->setSalary(sal);
}

//getSalary
double SalaryEmployee::getSalary() const
{
    return salary;
}

//setSalary
void SalaryEmployee::setSalary(const double& tmpSalary)
{
    salary = tmpSalary;
}

//output
ofstream& SalaryEmployee::output(ofstream& oFile) const 
{
    oFile << fixed << showpoint << setprecision(2);
    oFile << setw(25) << getName();
    oFile << setw(10) << getBDay();
    oFile << setw(12) << getSSN();
    oFile << setw(7) << getID();
    oFile << setw(10) << " ";
    oFile << setw(10) << " ";
    oFile << setw(10) << getSalary();
    oFile << "\n";
    return oFile;
}
