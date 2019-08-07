// File: employees.cpp
// Author: Joshua DeNio

//Description:
//This file contains the implimentation of the Employees class

#include "employees.h"

//pushback
template<class T>
void Employees<T>::pushback(const T& p)
{
    this->pushback(p);
}

//output
template<class T>
void Employees<T>::output() const
{
    ofstream ofs;
    string tmpName;
    Date tmpBDay;
    string tmpSSN;
    int tmpId;
    int tmpHours;
    double tmpWage;
    double tmpSalary;
    
    bool success=true;
    typename list<T>::const_iterator p;
    
    ofs.open("payroll");
    if (ofs.fail())
    {
        cerr << "error opening outputfile\n";
        success=false;
    }
    
    if(success)
    {
    
        ofs << fixed << showpoint << setprecision(2);
        ofs << setw(25) << "Name";
        ofs << setw(10) << "Birthday";
        ofs << setw(12) << "SSN";
        ofs << setw(7) << "ID";
        ofs << setw(10) << "Hours";
        ofs << setw(10) << "Wage";
        ofs << setw(10) << "Salary";
        ofs << "\n";
        
        for (p=list<T>::begin(); p!=list<T>::end(); p++)
        {
            ofs << *p;
            ofs << *p.output();
        }
    }
    ofs.close();
    //cout << *p << ' ';
    //cout << endl;
}
