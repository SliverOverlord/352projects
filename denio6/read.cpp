// File: read.h
// Author: Joshua DeNio

// Description: This file contains the function read. 


#ifndef _READ_H_
#define _READ_H_

#include "employee.h"
#include "hourlyEmployee.h"
#include "salaryEmployee.h"
#include "employees.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<class T>
Employees<T> read(ifstream& inFile, Employees<T> empList)
{
    //ifstream inFile;
    
    string tmpName;
    string tmpSSN;
    string tmpIdStr;
    string empType;
    
    //string dayStr;
    string tmpHoursStr;
    string tmpWageStr;
    string tmpSalaryStr;
    
    int m;
    int d;
    int y;
    
    Date tmpBDay;
    int tmpId;
    int tmpHours;
    double tmpWage;
    double tmpSalary;
    
    //inFile.open(inF);
    while(!inFile.eof())
    {
        
        //get the data to build an object
        getline(inFile, tmpName);
        //getline(inFile, dayStr);
        
        //inFile >> tmpBDay;
        inFile >> d;
        inFile.ignore('/');
        inFile >> m;
        inFile.ignore('/');
        inFile >> y;
        
        inFile.ignore(80,'\n');
        tmpBDay = Date(m,d,y);
        
        getline(inFile, tmpSSN);
        //getline(inFile, tmpIdStr);
        inFile >> tmpId;
        inFile.ignore(80,'\n');
        
        //get type
        getline(inFile, empType);
        if (empType == "H")
        {
            getline(inFile, tmpHoursStr);
            getline(inFile, tmpWageStr);
            
            HourlyEmployee emp = HourlyEmployee(tmpName,tmpBDay,tmpSSN,tmpId,tmpHours,tmpWage);
            empList.pushback(emp);
        }
        else
        {
            getline(inFile, tmpSalaryStr);
            
            SalaryEmployee emp = SalaryEmployee();
            empList.pushback(emp);
        }
        
        
        
        
    }
    inFile.close();
    //return inFile;
    return empList;
    
}
// Date parseDate(string dateString)
// {
//     int m;
//     int d;
//     int y;
//     
//     
//     Date newDate = Date(m,d,y);
//     
//     return newDate;
// }
#endif
