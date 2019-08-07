// File:     fraction.h
// Author:   Joshua DeNio

// Description
// This file contains the specification for the fraction class

#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
using namespace std;

enum output_Format {decimal,mixed,improper};

class fraction
{
    public:
        //fraction();
        
        // method - constructor
        // description - constructor for input of type int/int
        // preconditions - none
        // postconditions -  creates and initializes a new fraction
        // method input - double
        // method output - none
        fraction(int = 0,int = 1);
        
        // method - constructor
        // description - constructor for input of type double
        // preconditions - none
        // postconditions -  creates and initializes a new fraction
        // method input - double
        // method output - none
        fraction(double);
        
        // method - setNumerator
        // description - setter for numerator
        // preconditions - must have a valid fraction
        // postconditions -  sets a new numerator value
        // method input - int
        // method output - none
        void setNumerator(int);
        
        // method - setDenominator
        // description - setter for denominator
        // preconditions - must have a valid fraction
        // postconditions -  sets a new denominator value
        // method input - int
        // method output - none
        void setDenominator(int);
        
        // method - setFraction
        // description - setter for input of int/int
        // preconditions - must have a valid fraction
        // postconditions -  sets a new fraction value
        // method input - int, int
        // method output - none
        void setFraction(int,int);
        
        // method - setFraction
        // description - setter for input of type double
        // preconditions - must have a valid fraction
        // postconditions -  sets a new fraction value
        // method input - double
        // method output - none
        void setFraction(double);
        
        // method - getNumerator
        // description - returns the numerator of a fraction
        // preconditions - must have a valid fraction
        // postconditions -  none
        // method input - none
        // method output - int
        int getNumerator() const;
        
        // method - getDenominator
        // description - returns the denominator of a fraction
        // preconditions - must have a valid fraction
        // postconditions -  none
        // method input - none
        // method output - int
        int getDenominator() const;
        
        // method - reduce
        // description - reduces the fraction
        // preconditions - must have a valid fraction
        // postconditions -  fraction reduced
        // method input - none
        // method output - none
        void reduce();
        
        // method - decimalValue
        // description - returns the decimal value of a fraction
        // preconditions - must have a valid fraction
        // postconditions -  none
        // method input - none
        // method output - double
        double decimalValue() const;
        
        // method - outputFormat
        // description - setter for format
        // preconditions - none
        // postconditions -  format changed
        // method input - output_Format
        // method output - none
        static void outputFormat(output_Format);
        
        // method - getFormat
        // description - getter for format
        // preconditions - none
        // postconditions -  none
        // method input - none
        // method output - output_Format
        static output_Format getFormat();
        
        // method - override +
        // description - override +
        // preconditions - none
        // postconditions -  none
        // method input - fraction
        // method output - fraction
        fraction operator+(const fraction&) const;
        
        // method - override -
        // description - override -
        // preconditions - none
        // postconditions -  none
        // method input - fraction
        // method output - fraction
        fraction operator-(const fraction&) const;
        
        // method - override *
        // description - override *
        // preconditions - none
        // postconditions -  none
        // method input - fraction
        // method output - fraction
        fraction operator*(const fraction&) const;
        
        // method - override /
        // description - override /
        // preconditions - none
        // postconditions -  none
        // method input - fraction
        // method output - fraction
        fraction operator/(const fraction&) const;
        
        // method - override =
        // description - override =
        // preconditions - none
        // postconditions -  none
        // method input - double
        // method output - fraction
        fraction operator=(double);
        
        // method - override ==
        // description - override ==
        // preconditions - must be a valid fraction
        // postconditions -  none
        // method input - fraction
        // method output - bool
        bool operator==(const fraction&) const;
        
        // method - override !=
        // description - override !=
        // preconditions - must be a valid fraction
        // postconditions -  none
        // method input - fraction
        // method output - bool
        bool operator!=(const fraction&) const;
        
        // method - override <
        // description - override <
        // preconditions - must be a valid fraction
        // postconditions -  none
        // method input - fraction
        // method output - bool
        bool operator<(const fraction&) const;
        
        // method - override >
        // description - override >
        // preconditions - must be a valid fraction
        // postconditions -  none
        // method input - fraction
        // method output - bool
        bool operator>(const fraction&) const;
        
        // method - override <=
        // description - override <=
        // preconditions - must be a valid fraction
        // postconditions -  none
        // method input - fraction
        // method output - bool
        bool operator<=(const fraction&) const;
        
        // method - override >=
        // description - override >=
        // preconditions - must be a valid fraction
        // postconditions -  none
        // method input - fraction
        // method output - bool
        bool operator>=(const fraction&) const;
        
    private:
        //Numerator
        int numerator;
        
        //Denominator
        int denominator;
        
        //Format
        static output_Format format;
};

// method - gcd
// description - GCD function
// preconditions - must be a valid fraction
// postconditions -  none
// method input - int numerator, int denominator
// method output - int gcd
int gcd(int, int);

// method - override <<
// description - override <<
// preconditions - must have a valid fraction
// postconditions -  none
// method input - ostream, fraction
// method output - returns ostream
ostream& operator<<(ostream&,const fraction&);

// method - override >>
// description - override >>
// preconditions - must have a valid fraction
// postconditions -  returns istream fraction
// method input - istream, fraction
// method output - istream
istream& operator>>(istream&,fraction&);
#endif
