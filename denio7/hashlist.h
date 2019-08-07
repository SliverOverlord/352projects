// File: hash.h
// Author: Joshua DeNio
// Date: 5/6/19

// Description:
/*
Defines the hash class(a linked list.
*/

#ifndef _HASHLIST_H_
#define _HASHLIST_H_

#include <list>

using namespace std;

template <class T>
class hashList : public list<T>
{
    public:
        // method - insert
        // description - inserts an item into the list
        // preconditions - must have a valid list
        // postconditions -  item of type T added
        // method input - item of type T
        // method output - none
        void insert(const T&);
        
        // method - add
        // description - adds a hashed item to the list
        // preconditions - must have a valid list
        // postconditions -  item added
        // method input - item of type T
        // method output - none
        int add(const T&);
        
        // method - search
        // description - searches for an item
        // preconditions - must have a valid hashList
        // postconditions -  none
        // method input - item of type T
        // method output - bool
        bool search(const T&);
        
        // method - retrieve
        // description - retrieves an item
        // preconditions - must have a valid hashList
        // postconditions -  none
        // method input - item of type T
        // method output - bool
        void retrieve(T&);
        
        void print() const;
        void traverse(void (*) (T&));
};

//traverse
template <class T>
void hashList<T>::traverse(void (*funcPtr) (T&))
{
   typename list<T>::iterator p;
   for (p=list<T>::begin(); p!=list<T>::end(); p++)
      funcPtr(*p);
}

//print
template <class T>
void hashList<T>::print() const
{
    typename list<T>::const_iterator p;
    for (p=list<T>::begin(); p!=list<T>::end(); p++)
       cout << *p << ' ';
    cout << endl;
}

//insert
template <class T>
void hashList<T>::insert(const T& newitem)
{
    typename list<T>::iterator p;
    p = list<T>::begin();
    while (p!=list<T>::end() && newitem>*p)
       p++;
    list<T>::insert(p,newitem);
}

//add
template<class T>
int hashList<T>::add(const T& item)
{
    int col = 0;
    
    typename list<T>::const_iterator p;
    for (p=list<T>::begin(); p!=list<T>::end(); p++)
    {
        if(*p == item)
        {
            throw logic_error("The item is allready in the table");
        }
    }
    
    list<T>::push_back(item);
   
    if(list<T>::size() > 1)
    {
        col = 1;
    }
    
    return col;
}

//search
template<class T>
bool hashList<T>::search(const T& item)
{
    typename list<T>::const_iterator p;
    for (p=list<T>::begin(); p!=list<T>::end(); p++)
    {
        if(*p == item)
        {
            return true;
        }
    }
    return false;
}

//retrieve
template<class T>
void hashList<T>::retrieve(T& item)
{
    typename list<T>::const_iterator p;
    for (p=list<T>::begin(); p!=list<T>::end(); p++)
    {
        if(*p == item)
        {
            cout << *p << endl;
        }
    }
}


#endif
