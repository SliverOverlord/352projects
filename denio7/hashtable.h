// File: hashtable.h
// Author: Joshua DeNio
// Date: 5/6/19

// Description:
/*
Defines the hashtable class(an array of hashLists.
*/

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <iostream>
#include <stdexcept>
#include <list>
#include <array>
#include "hashlist.h"
#include "constants.h"

using namespace std;

template<class T>
class HashTable
{

public:
    
    // method - constructor
    // description - constructor
    // preconditions - none
    // postconditions -  creates a hashtable
    // method input - int size function pointer
    // method output -none
    HashTable(const int&, int (*fp)(const T&));
    
    // method - deconstructor
    // description - deconstructor 
    // preconditions - must have a valid object to delete
    // postconditions -  deletes a hashtable
    // method input - none
    // method output - none
    //~HashTable();
    
    // method - dump
    // description - prints the contense of the hashtable
    // preconditions - must have a valid object
    // postconditions -  none
    // method input - none
    // method output - none
    void dump() const;
    
    // method - collisions
    // description - counts and returns the number of collisions
    // preconditions - must have a valid object
    // postconditions -  none
    // method input - none
    // method output - int
    int collisions() const;
    
    // method - insert
    // description - inserts a linkedlist of type T
    // preconditions - must have a valid HashTable
    // postconditions -  adds an element to the HashTable
    // method input - item of type T
    // method output - none
    void insert(const T& );
    
    // method - search
    // description - searches for an item
    // preconditions - must have a valid hash HashTable
    // postconditions -  none
    // method input - item of type T
    // method output - bool
    bool search(const T&);
    
    // method - retrieve
    // description - retrieves an item 
    // preconditions - must have a valid object
    // postconditions -  retrieves an item
    // method input - T&
    // method output - none
    void retrieve(T&);
private:
    array<hashList<T>,TABLE_SIZE> hashArray;
    //hashList<T> hashArray;
    //FunctionPointer<T> funkP;
    int (*fptr)(const T&);
    //fptr fpVar;
    int collisionCount = 0;
    
};

//constructor
template<class T>
HashTable<T>::HashTable(const int& arraySize, int (*fp)(const T&))
{
    //const int num = 13;
    //hashArray = new array<T,num>{};
    //hashArray = [arraySize];
    
    fptr = fp;
}

//insert
template<class T>
void HashTable<T>::insert(const T& tmpIn)
{
    int num = fptr(tmpIn);
    hashList<T> hash = hashList<T>();
    collisionCount += hash.add(tmpIn);
    hashArray[num] = hash;
}

//collisions
template<class T>
int HashTable<T>::collisions() const
{
    return collisionCount;
}

//search
template<class T>
bool HashTable<T>::search(const T& item)
{
    bool found = false;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (found == true)
        {
            return true;
        }
        found = hashArray[i].search(item);
    }
    return found;
}

//dump
template<class T>
void HashTable<T>::dump() const
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashArray[i].print();
    }
}

//retrieve
template<class T>
void HashTable<T>::retrieve(T& item)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        
        hashArray[i].retrieve(item);
    }
}

#endif
