// File: Person.cpp
// Author: Joshua DeNio

//Description
/*
This file contains the implementation for the Person class

*/

#include "person.h"

//getName
string Person::getName() const
{
    return name;
}

//getBDay
Date Person::getBDay() const
{
    return bDay;
}

//getSSN
string Person::getSSN() const
{
    return SSN;
}

//setName
void Person::setName(const string& tmpName)
{
    name = tmpName;
}

//setBDay
void Person::setBDay(const Date& tmpBDay)
{
    bDay = tmpBDay;
}

//setSSN
void Person::setSSN(const string& tmpSSN)
{
    SSN = tmpSSN;
}
