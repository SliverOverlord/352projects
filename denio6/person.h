// File: person.h
// Author: Joshua DeNio

//Description
/*
This file contains the specification for the person class

*/

#ifndef _PERSON_H_
#define _PERSON_H_

#include "date.h"

using namespace std;

class Person{
    public:
        // method - getName
        // description - getter for name
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - string
        string getName() const;
        
        // method - getBDay
        // description - getter for BDay
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - Date
        Date getBDay() const;
        
        // method - getSSN
        // description - getter for SSN
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - string
        string getSSN() const;
        
        // method - setName
        // description - setter for name
        // preconditions - must have a valid object
        // postconditions -  changes the name
        // method input - string
        // method output -none
        void setName(const string&);
        
        // method - setBDay
        // description - setter for BDay
        // preconditions - must have a valid object
        // postconditions -  changes the birthday
        // method input - Date
        // method output - none
        void setBDay(const Date&);
        
        // method - setSSN
        // description - setter for SSN
        // preconditions - must have a valid object
        // postconditions -  sets the SSN
        // method input - string
        // method output - none
        void setSSN(const string&);

    private:
        //name
        string name;
        
        //birthday
        Date bDay;
        
        //SSN
        string SSN;
        
};


#endif

