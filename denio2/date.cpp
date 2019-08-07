// File: Date.cpp
// Author:  Joshua DeNio
// Program: 2
// Date:    02/20/19

// Description: This file contains code for the Date class

// Function: Date class
// Description: This file contains the Date class
// Input:  
// Output: 
// Preconditions:  None.
// Postconditions: creates a Date object.

#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>

#include "date.h"
using namespace std;
using namespace DateNameSpace;


//default constructor
Date::Date()
{
   setDate();
   
}


Date::Date(int m, int d, int y)
{
   setDate(m,d,y);
   
}

void Date::setDate(){
    
    tm *current;
    time_t lt;
    lt = time(0);
    current = localtime(&lt);
    year = current->tm_year + 1900;
    month = current->tm_mon+1;
    day = current->tm_mday;

    
}

void Date::setToday(){
    tm *current;
    time_t lt;
    lt = time(0);
    current = localtime(&lt);
    this->year = current->tm_year + 1900;
    this->month = current->tm_mon+1;
    this->day = current->tm_mday;
}

Date Date::Today(){
    Date d = Date();
    return d;
    
}

void Date::setDate(int m, int d, int y){
    bool validity;
    validity = isValid(m,d,y);
    if(validity == false){
      throw DateException("Invalid Date");   
    }
    else{
        day = d;
        month = m;
        year = y;
    }
    
}

void Date::setDay(int d){
    day = d;
    
}

void Date::setMonth(int m){
    month = m;
    
}

void Date::setYear(int y){
    year = y;
    
}

int Date::getDay() const {
    
    return day;
}

int Date::getMonth() const {
    
    return month;
}

int Date::getYear() const {
    
    return year;
}

string Date::getDate() const{
    //fill
}



bool Date::leapyear(int year) const{
   return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}


bool Date::isValid(int m,int d,int y){
    bool validity =true;
    bool leapY = leapyear(y);
    int count = 0;
    if(d > 31 || d < 1)
      validity = false;
    if (m < 1 || m > 12)
      validity = false;
    if ( (d>=31) && (m==2 || m==4 || m==6 || m==9 || m==11) ){
     validity = false;
    }
    if ( (d>=29) && (m==2) ){
     validity = false;
        
    }
    if (leapY == false && day >28){
        validity = false;
    }
    
    return validity;
    
    
}

string Date::getDayOfWeek() const{
    int centuries;
    int months;
    int dayofweek;
    
    string dayStr = "";
    
    centuries = (3-year/100%4)*2;
   switch (month)
    {
       case 1  : if (leapyear(year))
                    months = 6;
                 else
                    months = 0; 
                 break;
       case 2  : if (leapyear(year))
                    months = 2;
                 else
                    months = 3; 
                 break;
       case 3  : months = 3; break;
       case 4  : months = 6; break;
       case 5  : months = 1; break;
       case 6  : months = 4; break;
       case 7  : months = 6; break;
       case 8  : months = 2; break;
       case 9  : months = 5; break;
       case 10 : months = 0; break;
       case 11 : months = 3; break;
       case 12 : months = 5; break;
    }
    dayofweek = (centuries+year%100+year%100/4+months+day)%7;
 
    switch (dayofweek)
    {
       case 0 : dayStr = "Sunday"; break;
       case 1 : dayStr = "Monday"; break;
       case 2 : dayStr = "Tuesday"; break;
       case 3 : dayStr = "Wednesday"; break;
       case 4 : dayStr = "Thursday"; break;
       case 5 : dayStr = "Friday"; break;
       case 6 : dayStr = "Saturday"; break;
    }
    
    return dayStr;
}

string Date::getMonthName() const{
    string monthStr = "";
    
    switch (month)
    {
       case 1  : monthStr = "January"; break;
       case 2  : monthStr = "Febuary"; break;
       case 3  : monthStr = "March"; break;
       case 4  : monthStr = "April"; break;
       case 5  : monthStr = "May"; break;
       case 6  : monthStr = "June"; break;
       case 7  : monthStr = "July"; break;
       case 8  : monthStr = "August"; break;
       case 9  : monthStr = "September"; break;
       case 10 : monthStr = "October"; break;
       case 11 : monthStr = "November"; break;
       case 12 : monthStr = "December"; break;
    }
    return monthStr;
}


istream& operator>>(istream& inS,Date& d)
{
   int tempDay;
   int tempMon;
   int tempYear;
   
   inS >> tempMon ;
   
   inS.ignore();
   
   inS >> tempDay;
   
   inS.ignore();
   
   inS >> tempYear;
   
   d.setDate(tempMon, tempDay, tempYear);
   
   
   cout << endl;
   
   return inS;
}

ostream& operator<<(ostream& out,const Date& d)
{
    int tmpDay;
    int tmpMonth;
    int tmpYear;
    
    output_Format outF;
    
    tmpDay = d.getDay();
    tmpMonth = d.getMonth();
    tmpYear = d.getYear();
    
    outF = d.getFormat();
    
    if (outF == MiddleEndian){
        out << d.MiddleEndianValue();
        
    }
    else if(outF == LittleEndian){
        
         out << d.LittleEndianValue();
    }
    else{
        out << d.BigEndianValue();
    } 
    
    
   return out;
}

string Date::MiddleEndianValue() const{
    string dateStr = "";
    string tmpDel = "";
    string tmpDay = "";
    string tmpMonth = "";
    string tmpYear = "";
    
    day_Format df;
    month_Format mf;
    Delimiter dl;
    
    df = getDayFormat();
    mf = getMonthFormat();
    dl = getDelFormat();
    
    if(dl == Slash){
        tmpDel = "/";
    }
    else if (dl == Dash){
     tmpDel = "-";   
    }
    else{
        tmpDel = " ";
    }
    
    
    if( df == Weekday){
        //find weekday
        dateStr += getDayOfWeek()+" ";        
    }
    tmpDay= to_string(getDay());
    
    if(mf==Numeric){
            tmpMonth = to_string(getMonth());
            
        }
    else{
        //find monthStr
        tmpMonth = getMonthName();
        tmpDel = " ";
        }
    
    tmpYear = to_string(getYear());
    
    dateStr += tmpMonth + tmpDel + tmpDay + tmpDel + tmpYear;
    
    
    return dateStr;
    
}


string Date::LittleEndianValue() const{
    string dateStr = "";
    string tmpDel = "";
    string tmpDay = "";
    string tmpMonth = "";
    string tmpYear = "";
    
    day_Format df;
    month_Format mf;
    Delimiter dl;
    
    df = this-> getDayFormat();
    mf = this-> getMonthFormat();
    dl = this-> getDelFormat();
    
    
    if(dl == Slash){
        tmpDel = "/";
    }
    else if (dl == Dash){
     tmpDel = "-";   
    }
    else{
        tmpDel = " ";
    }
    
    
    if( df == Weekday){
        //find weekday
        dateStr += getDayOfWeek()+" ";        
    }
    tmpDay= to_string(getDay());
    
    if(mf==Numeric){
            tmpMonth = to_string(getMonth());
            
        }
    else{
        //find monthStr
        tmpMonth = getMonthName();
        tmpDel = " ";
        }
    tmpYear = to_string(getYear());
    
    dateStr += tmpDay + tmpDel + tmpMonth + tmpDel + tmpYear;
    
    
    return dateStr;
    
}


string Date::BigEndianValue() const{
    string dateStr = "";
    string tmpDel = "";
    string tmpDay = "";
    string tmpMonth = "";
    string tmpYear = "";
    
    day_Format df;
    month_Format mf;
    Delimiter dl;
    
    df = this-> getDayFormat();
    mf = this-> getMonthFormat();
    dl = this-> getDelFormat();
    
    
    if(dl == Slash){
        tmpDel = "/";
    }
    else if (dl == Dash){
     tmpDel = "-";   
    }
    else{
        tmpDel = " ";
    }
    
    
    if( df == Weekday){
        //find weekday
        dateStr += getDayOfWeek()+" ";        
    }
    tmpDay= to_string(getDay());
    
    if(mf==Numeric){
            tmpMonth = to_string(getMonth());
            
        }
    else{
        //find monthStr
        tmpMonth = getMonthName();
        tmpDel = " ";
        }
    tmpYear = to_string(getYear());
    
    dateStr += tmpYear + tmpDel + tmpMonth + tmpDel + tmpDay;
    
    
    return dateStr;
    
}


void Date::outputFormat(output_Format f) {
 format = f;   
}

output_Format Date::format=MiddleEndian;

output_Format Date::getFormat() {
    return format;
}



void Date::outputFormat(day_Format f){
    dayF = f;
}

day_Format Date::dayF=NoWeekday;

day_Format Date::getDayFormat() {
    return dayF;
}



void Date::outputFormat(month_Format f){
    monthF = f;
}

month_Format Date::monthF=Numeric;

month_Format Date::getMonthFormat() {
    return monthF;
}


void Date::outputFormat(Delimiter f){
    delimiterF = f;
}

Delimiter Date::delimiterF=Slash;

Delimiter Date::getDelFormat(){
    
    return delimiterF;
}

Date Date::operator-(const Date& d) const{
    
    
}

// Date Date::operator=(Date d){
//     this->setDate(d.getMonth(), d.getDay(), d.getYear());
//     
// }

// Date Date::operator++(int i){
//     int[] monthList = [9,4,5,11];
//     int[] normList = [1,3,6,7,8,10,12];
//     if(getDay() <= 27){
//         setDay(getDay()+1);
//     }
//     else if (getMonth() in monthList && getDay() <= 29){
//         setDay(getDay()+1;
//     }
//     else if (getMonth() in normList && getDay() <= 30){
//         setDay(getDay()+1;
//     }
//     else{
//         setday(1);
//         if (getMonth()< 12){
//             setMonth(getMonth()+1);
//         }
//         else {
//             setMonth(1);
//             setYear(getYear()+1);
//         }
//     }
// }

// Date Date::operator--(int i){
//     int[] monthList = [9,4,5,11];
//     int[] normList = [1,3,6,7,8,10,12];
//     if(getDay() >= 2){
//         setDay(getDay()-1);
//     }
//     else if (getMonth() in monthList && getDay() <= 29){
//         setDay(getDay()+1;
//     }
//     else if (getMonth() in normList && getDay() <= 30){
//         setDay(getDay()+1);
//     }
//     else{
//         setday(1);
//         if (getMonth()< 12){
//             setMonth(getMonth()+1);
//         }
//         else {
//             setMonth(1);
//             setYear(getYear()+1);
//         }
//     }
// }

bool Date::operator==(const Date& d) const{
    if(d.getDay() == this-> getDay() && d.getMonth() == this-> getMonth() && d.getYear() == this-> getYear()){
        return true;
    }
    else {
        return false;
    }
    
}

bool Date::operator!=(const Date& d) const{
    if(d.getDay() == this-> getDay() && d.getMonth() == this-> getMonth() && d.getYear() == this-> getYear()){
        return false;
    }
    else {
        return true;
    }
}

bool Date::operator>=(const Date& d) const{
    if(getYear()>= d.getYear()){
        if(getMonth() >= d.getMonth()){
            if(getDay() >= d.getDay()){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;   
    }
    
}
