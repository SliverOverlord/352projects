// File:     fraction.cpp
// Author:   Joshua DeNio

// Description
// This file contains the implementation for the fraction class
#include <iostream>
#include "fraction.h"

fraction::fraction(int num, int den){
 setNumerator(num);
 setDenominator(den);
    
}

fraction::fraction(double num) {
    denominator = 1;

	while(((double)(int)num) != num) {
		num = num * 10;
		denominator = denominator * 10;
	}

	numerator = (int)num;	

	reduce();
    
}

void fraction::setNumerator(int tmpNumerator) {
	numerator = tmpNumerator;
}

void fraction::setDenominator(int tmpDenominator) {
    if(tmpDenominator == 0){
        cerr << "Denominator can not be 0.";
    }
    else{
        denominator = tmpDenominator;
    }
}

void fraction::setFraction(int num,int den) {
    setNumerator(num);
    setDenominator(den);
    
}

void fraction::setFraction(double num) {
    denominator = 1;

	while(((double)(int)num) != num) {
		num = num * 10;
		denominator = denominator * 10;
	}

	numerator = (int)num;	

	reduce();
    
}

void fraction::outputFormat(output_Format f) {
 format = f;   
}

output_Format fraction::format=mixed;

output_Format fraction::getFormat() {
    return format;
}

int gcd(int num, int den) {
    //int num = this->getNumerator();
    //int den = this->getDenominator();
    int rem;
    do  
    {   
        rem = num % den;  
        num = den;  
        den = rem;  
    } while ( rem != 0 ); 
    return num;
}

int fraction::getNumerator() const {
 return numerator;   
    
}

int fraction::getDenominator() const {
 return denominator;   
    
}

double fraction::decimalValue() const {
    return (double)this->numerator / (double)this->denominator;
    
}

void fraction::reduce() {
    int num = getNumerator();
    int den = getDenominator();
    
    int tmpgcd = gcd(num, den);
    
    if (1 < tmpgcd){
        num /= tmpgcd;
        den /= tmpgcd;
        
    }
    
    this->setNumerator(num);
    this->setDenominator(den);
}

istream& operator>>(istream& inS,fraction& f)
{
   int tempNum;
   int tempDen;
   
   inS >> tempNum ;
   
   inS.ignore(1,'/');
   
   inS >> tempDen;
   
   f.setNumerator(tempNum);
   f.setDenominator(tempDen);
   
   cout << endl;
   
   return inS;
}


ostream& operator<<(ostream& out,const fraction& f)
{
    int num;
    int den;
    int a;
    int b;
    int c;
    output_Format outF;
    
    num = f.getNumerator();
    den = f.getDenominator();
    outF = f.getFormat();
    
    if (outF == decimal){
        out << f.decimalValue();
    }
    else if(outF == mixed){
        if(num >= den || num < den){
                a = num/den;
                c = a*den;
                b = num-c;
                if(b == 0){
                    out << a;
                }
                else if(a == 0){
                    out << b << "/" << den;
                }
                else{
                    if(b < 0){
                        b = b*(-1);
                    }
                    else if(den < 0){
                        den = den * (-1);
                    }
                    out << a << " " << b << "/" << den;
                }
            }
            else{
                out << f.getNumerator() << "/" << f.getDenominator();
            }
    }
    else{
        out << f.getNumerator() << "/" << f.getDenominator();
    }
    /*
    switch (outF)
    {
        case decimal : out << f.decimalValue(); break;
        case mixed : {
            if(num >= den){
                a = num/den;
                c = a*den;
                b = num-c;
                if(b == 0){
                    out << a;
                }
                else{
                    out << a << " " << b << "/" << den;
                }
            }
            else{
                out << f.getNumerator() << "/" << f.getDenominator();
            }
        }; break;
      case improper : out << f.getNumerator() << "/" << f.getDenominator();; break;
   }
   */
    
    
    
   return out;
}

fraction fraction::operator+(const fraction& f) const
{
    int num1, den1, num2, den2, num3, den3;
    
    num1 = getNumerator();
    den1 = getDenominator();
    num2 = f.getNumerator();
    den2 = f.getDenominator();
    
    num3 = (num1*den2) + (num2*den1);
    den3 = den1 * den2;
    
    fraction temp(num3, den3);
    temp.reduce();
    return temp;
}

fraction fraction::operator-(const fraction& f) const
{
    int num1, den1, num2, den2, num3, den3;
    
    num1 = getNumerator();
    den1 = getDenominator();
    num2 = f.getNumerator();
    den2 = f.getDenominator();
    
    num3 = (num1*den2) - (num2*den1);
    den3 = den1 * den2;
    
    fraction temp(num3, den3);
    temp.reduce();
    return temp;
}

fraction fraction::operator*(const fraction& f) const
{
    int num1, den1, num2, den2, num3, den3;
    
    num1 = getNumerator();
    den1 = getDenominator();
    num2 = f.getNumerator();
    den2 = f.getDenominator();
    
    num3 = num1 * num2;
    den3 = den1 * den2;
    
    fraction temp(num3, den3);
    temp.reduce();
    return temp;
}

fraction fraction::operator/(const fraction& f) const
{
    int num1, den1, num2, den2, num3, den3;
    
    num1 = getNumerator();
    den1 = getDenominator();
    num2 = f.getNumerator();
    den2 = f.getDenominator();
    
    num3 = num1 * den2;
    den3 = den1 * num2;
    
    fraction temp(num3, den3);
    temp.reduce();
    return temp;
}

fraction fraction::operator=(double d)
{
   setFraction(d);
   return *this;
}


bool fraction::operator==(const fraction& f) const
{
    double a, b;
    a = decimalValue();
    b = f.decimalValue();
    if(a == b){
        return true;
    }
    else{
        return false;
    }
}

bool fraction::operator!=(const fraction& f) const
{
    double a, b;
    a = decimalValue();
    b = f.decimalValue();
    if(a != b){
        return true;
    }
    else{
        return false;
    }
}

bool fraction::operator<(const fraction& f) const
{
   double a, b;
    a = decimalValue();
    b = f.decimalValue();
    if(a < b){
        return true;
    }
    else{
        return false;
    }
    
}

bool fraction::operator>(const fraction& f) const
{
   double a, b;
    a = decimalValue();
    b = f.decimalValue();
    if(a > b){
        return true;
    }
    else{
        return false;
    }
    
}

bool fraction::operator<=(const fraction& f) const
{
   return *this == f || *this < f;
}

bool fraction::operator>=(const fraction& f) const
{
   return *this == f || *this > f;
}





