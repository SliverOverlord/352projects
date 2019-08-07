// File:     Date.h
// Author:   Joshua DeNio

// Description
// This file contains the specification for the Date class

#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
using namespace std;

namespace DateNameSpace{
    
 class DateException
{
   public:
      DateException(const string& m="")
      { msg = m; }

      string what()
      { return msg; }

   private:
      string msg;
};
   
    
}


enum output_Format {LittleEndian,MiddleEndian,BigEndian};
enum Delimiter {Slash,Dash, Space};
enum month_Format{Text, Numeric};
enum day_Format{Weekday, NoWeekday};
enum Arithmetic_Format {Years,Days,Months};


class Date
{
    public:
        // method - default constructor
        // description - constructor for no input 
        // preconditions - none
        // postconditions -  creates and initializes a new Date
        // method input - none
        // method output - none
        Date();
        
        // method - constructor
        // description - constructor for input of type int,int,int
        // preconditions - none
        // postconditions -  creates and initializes a new Date
        // method input - int
        // method output - none
        Date(int,int,int);
        
        
        // method - setDay
        // description - setter for day
        // preconditions - must have a valid Date
        // postconditions -  sets a new day value
        // method input - int
        // method output - none
        void setDay(int);
        
        // method - setMonth
        // description - setter for month
        // preconditions - must have a valid Date
        // postconditions -  sets a new month value
        // method input - int
        // method output - none
        void setMonth(int);
        
        // method - setYear
        // description - setter for year
        // preconditions - must have a valid Date
        // postconditions -  sets a new year value
        // method input - int
        // method output - none
        void setYear(int);
        
        
        // method - setDate
        // description - setter for input of int/int
        // preconditions - must have a valid Date
        // postconditions -  sets a new Date value
        // method input - int, int, int
        // method output - none
        void setDate(int,int,int);
        
        // method - setDate
        // description - setter for input of null
        // preconditions - must have a valid Date
        // postconditions -  sets a new Date value
        // method input - none
        // method output - none
        void setDate();
        
        
        // method - Today
        // description - setter for Today
        // preconditions - must have a valid Date
        // postconditions -  sets a new Date value
        // method input - none
        // method output - none
        static Date Today();
        
        
        // method - Today
        // description - setter for Today
        // preconditions - must have a valid Date
        // postconditions -  sets a new Date value
        // method input - none
        // method output - none
        void setToday();
        
        // method - getDay
        // description - returns the day
        // preconditions - must have a valid Date
        // postconditions -  none
        // method input - none
        // method output - int
        int getDay() const;
        
        
        // method - getMonth
        // description - returns the month
        // preconditions - must have a valid Date
        // postconditions -  none
        // method input - none
        // method output - int
        int getMonth() const;
        
        
        // method - getYear
        // description - returns the year
        // preconditions - must have a valid Date
        // postconditions -  none
        // method input - none
        // method output - int
        int getYear() const;
        
        
        // method - getDate
        // description - returns the Date
        // preconditions - must have a valid Date
        // postconditions -  none
        // method input - none
        // method output - Date string
        string getDate() const;
        
        // method - leapyear
        // description - returns a bool
        // preconditions - must have a valid Date
        // postconditions -  none
        // method input - int
        // method output - bool
        bool leapyear(int) const;
        
        // method - isValid
        // description - returns a bool
        // preconditions - none
        // postconditions -  none
        // method input - int
        // method output - bool
        bool isValid(int,int,int);
        
        // method - getDayOfWeek
        // description - returns the weekday
        // preconditions - must have a valid Date
        // postconditions -  none
        // method input - none
        // method output - string
        string getDayOfWeek() const;
        
        // method - getMonthName
        // description - returns the monthName
        // preconditions - must have a valid Date
        // postconditions -  none
        // method input - none
        // method output - string
        string getMonthName() const;
        
        // method - MiddleEndianValue
        // description - returns a string
        // preconditions - must have a valid Date
        // postconditions -  none
        // method input - none
        // method output - string
        string MiddleEndianValue()const;
        
        // method - LittleEndianValue
        // description - returns a string
        // preconditions - must have a valid Date
        // postconditions -  none
        // method input - none
        // method output - string
        string LittleEndianValue()const;
        
        // method - BigEndianValue
        // description - returns a string
        // preconditions - must have a valid Date
        // postconditions -  none
        // method input - none
        // method output - string
        string BigEndianValue()const;
        
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
        
        // method - outputFormat
        // description - setter for format
        // preconditions - none
        // postconditions -  format changed
        // method input - day_Format
        // method output - none
        static void outputFormat(day_Format);
        
        // method - getFormat
        // description - getter for format
        // preconditions - none
        // postconditions -  none
        // method input - none
        // method output - day_Format
        static day_Format getDayFormat();
        
        // method - outputFormat
        // description - setter for format
        // preconditions - none
        // postconditions -  format changed
        // method input - month_Format
        // method output - none
        static void outputFormat(month_Format);
        
        // method - getFormat
        // description - getter for format
        // preconditions - none
        // postconditions -  none
        // method input - none
        // method output - month_Format
        static month_Format getMonthFormat();
        
        // method - outputFormat
        // description - setter for format
        // preconditions - none
        // postconditions -  format changed
        // method input - Delimiter
        // method output - none
        static void outputFormat(Delimiter);
        
        // method - getFormat
        // description - getter for format
        // preconditions - none
        // postconditions -  none
        // method input - none
        // method output - Delimiter
        static Delimiter getDelFormat();
        
        // method - Arithmetic
        // description - setter for Arithmetic
        // preconditions - none
        // postconditions -  format changed
        // method input - Arithmetic_Format
        // method output - none
        static void Arithmetic(Arithmetic_Format);
        
        // method - getArithmetic
        // description - getter for Arithmetic
        // preconditions - none
        // postconditions -  none
        // method input - none
        // method output - Arithmetic_Format
        static Arithmetic_Format getArithmetic();
        
        // method - override +
        // description - override +
        // preconditions - none
        // postconditions -  none
        // method input - Date
        // method output - 
        Date operator+(const Date&) const;
        
        // method - override -
        // description - override -
        // preconditions - none
        // postconditions -  none
        // method input - Date
        // method output - Date
        Date operator-(const Date&) const;
        
        // method - override ++
        // description - override ++
        // preconditions - must be a valid Date
        // postconditions -  none
        // method input - Date
        // method output - bool
        Date operator++(int i);
        
        
        // method - override --
        // description - override --
        // preconditions - must be a valid Date
        // postconditions -  none
        // method input - Date
        // method output - bool
        Date operator--(int i);
        
        
        // method - override ==
        // description - override ==
        // preconditions - must be a valid Date
        // postconditions -  none
        // method input - Date
        // method output - bool
        bool operator==(const Date&) const;
        
        // method - override !=
        // description - override !=
        // preconditions - must be a valid Date
        // postconditions -  none
        // method input - Date
        // method output - bool
        bool operator!=(const Date&) const;
        
        // method - override <
        // description - override <
        // preconditions - must be a valid Date
        // postconditions -  none
        // method input - Date
        // method output - bool
        bool operator<(const Date&) const;
        
        // method - override >
        // description - override >
        // preconditions - must be a valid Date
        // postconditions -  none
        // method input - Date
        // method output - bool
        bool operator>(const Date&) const;
        
        // method - override <=
        // description - override <=
        // preconditions - must be a valid Date
        // postconditions -  none
        // method input - Date
        // method output - bool
        bool operator<=(const Date&) const;
        
        // method - override >=
        // description - override >=
        // preconditions - must be a valid Date
        // postconditions -  none
        // method input - Date
        // method output - bool
        bool operator>=(const Date&) const;
        
    private:
        //day
        int day;
        
        //month
        int month;
        
        //year
        int year;
        
        //Format
        static output_Format format;
        
        //dayFormat
        static day_Format dayF;
        
        //MonthFormat
        static month_Format monthF;
        
        //delimiterFormat
        static Delimiter delimiterF;
};


// method - override <<
// description - override <<
// preconditions - must have a valid Date
// postconditions -  none
// method input - ostream, Date
// method output - returns ostream
ostream& operator<<(ostream&,const Date&);

// method - override >>
// description - override >>
// preconditions - must have a valid Date
// postconditions -  returns istream Date
// method input - istream, Date
// method output - istream
istream& operator>>(istream&,Date&);
#endif
