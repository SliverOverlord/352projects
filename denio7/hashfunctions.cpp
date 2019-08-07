// File: hashfunctions.cpp
// Author: Joshua DeNio
// Date: 5/6/19

// Description:
/*
Impliments the hashfunctions.
*/
#include "symbol.h"
#include "constants.h"
#include <stdexcept>
using namespace std;


int hash1(const Symbol& value)
{
    int val = value.getValue();
    if(val >= TABLE_SIZE)
    {
        throw range_error("Hash out of range");
    }
    return val;
}
int hash2(const int& value)
{
    int val = value % TABLE_SIZE;
    if(val >= TABLE_SIZE)
    {
        throw range_error("Hash out of range");
    }
    return val;
}

// int hash1(string str)
// {
//     int val = 0;
//     for (int i = 0; i < str.length(); i++)
//     {
//         val += str[i];
//     }
//     return val % tableSize;
// }
