//Author: Joshua DeNio
//File: main
//Description:
// This is the main funtion for the aplication.
#include <iostream>
#include <fstream>

using namespace std;

#include "date.h"
#include "person.h"
#include "employee.h"
#include "salaryEmployee.h"
#include "employees.h"
#include <stdexcept>

// method - read
// description - reads from a file
// preconditions - none
// postconditions -  creates objects and adds them to the list
// method input - istream
// method output - returns istream
template<class T>
Employees<T> read(ifstream&, Employees<T>);

int main(int argc, char *argv[])
{
    ifstream iFstream;
    ofstream oFstream;
    Employees<Employee*> empList;
    
    bool success = true;
    try{
        if (argc != 2)
        {
            //cerr << "usage: " << argv[0] << " <inputfile>\n";
            success=false;
            throw  invalid_argument("Usage: invalid program name <inputfile>\n");
        }
        else
        {
            iFstream.open(argv[1]);
            if (iFstream.fail())
            {
                //cerr << "error opening inputfile: '" << argv[1] << "' doesn't exist?\n";
                success=false;
                throw invalid_argument ("error opening inputfile: file does not exist\n") ;
            }
    
        }
    }
    catch(invalid_argument error)
    {
        success = false;
        cout << error.what();
    }
    
   if (success)
   {
        iFstream = read(iFstream, empList);
        empList.output();
//         for(i = empList.begin(); i < empList.end(); i++)
//         {
//             
//         }
        //iFstream.close();
        //oFstream.close();
   }
    
    
    return 0;
}


