#ifndef _SORTEDLIST_H_
#define _SORTEDLIST_H_

#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;
namespace sortedListSpace{
    
    enum order_Format {ASCENDING,DESCENDING};
    enum traverseType {increment,visit};
    
    //Definition of the linked node
    template <class T>
    struct node{
        T item;
        node<T> *link;
        
    };
 
    template <class T>
    
    
    class sortedList{
    public:
        // method - constructor
        // description - constructor
        // preconditions - none
        // postconditions -  creates an empty sortedList
        // method input - none
        // method output -none
        sortedList();
        
        // method - constructor for format input
        // description - constructor
        // preconditions - none
        // postconditions -  creates an empty sortedList
        // method input - order_Format
        // method output -none
        sortedList(order_Format);
        
        // method - deconstructor
        // description - deconstructor 
        // preconditions - must have a valid object to delete
        // postconditions -  deletes a sortedList
        // method input - none
        // method output - none
        ~sortedList();
        
        // method - copy constructor
        // description - copy constructor
        // preconditions - must have a valid object
        // postconditions -  creates a new object
        // method input - a sortedList
        // method output - a new copy of the sortedList
        sortedList(const sortedList<T>&);
        
        
        // method - operator overload for =
        // description - overloads =
        // preconditions - must have a valid object
        // postconditions -  sets one sorted list to equal another
        // method input - a darget and destination
        // method output - none
        const sortedList<T>& operator = (const sortedList<T>&);
        
        // method - override ==
        // description - override ==
        // preconditions - must be a valid object
        // postconditions -  none
        // method input - none
        // method output - bool
        bool operator == (const sortedList&) const;
        
        // method - override !=
        // description - override !=
        // preconditions - must be a valid sortedList
        // postconditions -  none
        // method input - sortedList
        // method output - bool
        bool operator!=(const sortedList<T>&) const;
        
        // method - override <
        // description - override <
        // preconditions - must be a valid sortedList
        // postconditions -  none
        // method input - sortedList
        // method output - bool
        bool operator<(const sortedList<T>&) const;
        
        // method - override >
        // description - override >
        // preconditions - must be a valid sortedList
        // postconditions -  none
        // method input -sortedList
        // method output - bool
        bool operator>(const sortedList&) const;
        
        // method - override <=
        // description - override <=
        // preconditions - must be a valid sortedList
        // postconditions -  none
        // method input - sortedList
        // method output - bool
        bool operator<=(const sortedList&) const;
        
        // method - length
        // description - getter for length
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - this
        // method output - int
        int length() const;
        
        // method - operator []
        // description - overrides []
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - this
        // method output - T&
        //T& operator[](int index);
        
        // method - const operator []
        // description - overrides [] throws out_of_range exception
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - an index
        // method output - returns a pointer
        const T& operator[](int index) const;
        
        // method - Ascending
        // description - Ascending sort
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - a acending sortedList
        sortedList<T> ascending() const;
        
        // method - Descending
        // description - Descending sort
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output - a decending sortedList
        sortedList<T> Descending() const;
    
        // method - traverse
        // description - traverses the sortedList
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - traverseType
        // method output - none
        void traverse(traverseType input);
        
        // method - insertItem
        // description - inserts an item to the sortedList
        // preconditions - must have a valid object
        // postconditions -  new item added
        // method input - item of type T
        // method output - none
        void insertItem(T item);
        
        // method - deleteItem
        // description - removes an item from the sortedList
        // preconditions - must have a valid object
        // postconditions -  item removed
        // method input - item of type T
        // method output - none
        void deleteItem(const T& item);
        
        // method - deleteAll
        // description - removes all matching items from the sortedList
        // preconditions - must have a valid object
        // postconditions -  items removed
        // method input - item of type T
        // method output - none
        void deleteAll(T item);
        
        // method - removeDuplicates()
        // description - removes duplicats from the sortedList
        // preconditions - must have a valid object
        // postconditions -  items removed
        // method input - none
        // method output - none
        void removeDuplicates();
        
        // method - isEmptyList
        // description - tests for empty list
        // preconditions - must have a valid object
        // postconditions - returns true if the sortedList is empty 
        // method input - this
        // method output -bool
        bool isEmptyList() const;
        
        // method - destroyList()
        // description - removes a sortedList
        // preconditions - must have a valid object
        // postconditions -  sortedList removed
        // method input - this
        // method output - none
        void destroyList();
        
        // method - valueAt
        // description - valueAt returns a value and can throw out_of_range exception
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - index
        // method output - value type T
        T& valueAt(int) const;
        
        // method - inList
        // description - returns true if item is in the list
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - item of type<T>
        // method output - bool
        bool inList(int) const;
        
        // method - merge
        // description - merges two SortedLists
        // preconditions - must have tow sortedLists
        // postconditions -  merges two lists
        // method input - a sortedList
        // method output - none
        void merge(const sortedList<T>& list1);
        
        
        // method - setOrder
        // description - setter for order
        // preconditions - none
        // postconditions -  format changed
        // method input - order_Format
        // method output - none
         void setOrder(order_Format);
        
        // method - getFormat
        // description - getter for format
        // preconditions - none
        // postconditions -  none
        // method input - none
        // method output - output_Format
        order_Format getFormat();
        
        
    private:
        int count;
        node<T> *first;
        node<T> *last;
        //Format
        static order_Format format;
        
        // method - copyList
        // description - copies a list
        // preconditions - must have a valid object
        // postconditions -  creates a copy
        // method input - this
        // method output - a new sortedList
        void copySortedList(const sortedList<T>& list1);
        
        // method - 
        // description - 
        // preconditions - 
        // postconditions -  
        // method input - 
        // method output - 
    };
    
    //default constructor
    template<class T>
    sortedList<T>::sortedList(){
        first = NULL;
        last = NULL;
        count = 0;
        format = ASCENDING;
    }
    
    //constructor for orderinput
    template<class T>
    sortedList<T>::sortedList(order_Format tmp){
        first = NULL;
        last = NULL;
        count = 0;
        format = tmp;
    }
    
    //destructor
    template<class T>
    sortedList<T>::~sortedList(){
        destroyList();
    }
    
    //destroyList
    template<class T>
    void sortedList<T>::destroyList(){
        node<T> *tmp;
        
        while(first != NULL){
            tmp = first;
            first = first->link;
            delete tmp;
        }
        last = NULL;
        count = 0;
        
    }
    
    //copy constructor
    template<class T>
    sortedList<T>::sortedList(const sortedList<T>& list1){
        first = NULL;
        copySortedList(list1);
    }
    
    //function to copy a sortedList
    template<class T>
    void sortedList<T>::copySortedList(const sortedList<T>& list1){
        node<T> *newNode;
        node<T> *currentNode;
        
        
        if(first != NULL){
            destroyList();
        }
        if(list1.first == NULL){
            first = NULL;
            last = NULL;
            count = 0;
            format = list1.format;
        }
        else{
            currentNode = list1.first;
            count = list1.count;
            first = new node<T>;
            assert(first != NULL);
            first->item = currentNode->item;
            first->link = NULL;
            last = first;
            format = list1.format;
            currentNode = currentNode->link;
            
            while(currentNode != NULL){
                newNode = new node<T>;
                
                assert(newNode != NULL);
                
                newNode->item = currentNode->item;
                newNode->link = NULL;
                
                last->link = newNode;
                last = newNode;
                
                currentNode = currentNode->link;
            }
        }
    }
    
    //length
    template<class T>
    int sortedList<T>::length() const{
        return count;
    }
    
    //override for []
    template<class T>
    const T& sortedList<T>::operator[](int index) const{
        
        node<T> *currentNode;
        currentNode = first;
        if(index < count && index>=0){
            for(int i =0; i < index; i++){
                currentNode = currentNode->link;
                
            }
            return currentNode->item;
        }
        else{throw out_of_range("Index Out Of Range");}
    }
        
//         node<T> *currentNode;
//         bool found = false;
//         int tmpCount = 0;
//         int size = length();
//         
//         currentNode = first;
//         
//         if(currentNode == NULL){
//             throw out_of_range("The List Is Empty");
//         }
//         
//         if(tmpCount>=size || index < 0){
//                 throw out_of_range("Index Out Of Range");
//         }
//         
//         while(currentNode != NULL && !found){
//             if(tmpCount == index){
//                 return currentNode->item;
//                 
//             }
//             tmpCount++;
//             currentNode++;
//             
//         }
//     
// //         for( int i = 0; i <= index; i++){
// //            // cerr << currentNode->item<< " currentNode;;;;;" <<endl;
// //             currentNode++;
// //             //currentNode = currentNode->link;
// //         }
//         
//         return currentNode->item;
//       
//    }
//     
    
    //isEmptyList
    template<class T>
    bool sortedList<T>::isEmptyList() const{
        return(first == NULL);
        
    }
    
    //insertItem
    template<class T>
    void sortedList<T>::insertItem(T newItem){
        node<T> *currentNode;
        node<T> *newNode;
        
        node<T> *nextNode;
        
        newNode = new node<T>;
        nextNode = new node<T>;
        
        
        newNode->item = newItem;
        newNode->link = NULL;
        
        currentNode = first;
     
        
        if(first == NULL){
            first = newNode;
            last = newNode;
            
        }
        else{
            bool found = false;
        
            currentNode = first;
            
            
            if(format == ASCENDING){
                if(newNode->item <= currentNode->item){
                    
                    newNode->link = currentNode;
                    first = newNode;
                }
                else if(newNode->item >= currentNode->item && currentNode->link == NULL){
                            currentNode->link = newNode;
                            last = newNode;
                }
                else{
                    while(currentNode != NULL && found == false){
                        if(currentNode == last){
                            currentNode->link = newNode;
                            last = newNode;
                            found = true;
                        }
                        else{
                            nextNode = currentNode->link;
                        }
                        
                        if(currentNode->item <= newNode->item && nextNode->item >= newNode->item){
                            
                            newNode->link = currentNode->link;
                            currentNode->link = newNode;
                            found = true;
                        }
                        else{
                            currentNode = currentNode->link;
                        }
                    
                    }
                }
            }
            else{
                
                if(newNode->item >= currentNode->item){
                    
                    newNode->link = currentNode;
                    first = newNode;
                }
                else if(newNode->item <= currentNode->item && currentNode->link == NULL){
                            currentNode->link = newNode;
                            last = newNode;
                }
                else{
                    while(currentNode != NULL && found == false){
                        if(currentNode == last){
                            currentNode->link = newNode;
                            last = newNode;
                            found = true;
                        }
                        else{
                            nextNode = currentNode->link;
                        }
                        
                        if(currentNode->item >= newNode->item && nextNode->item <= newNode->item){
                            
                            newNode->link = currentNode->link;
                            currentNode->link = newNode;
                            found = true;
                        }
                        else{
                            currentNode = currentNode->link;
                        }
                    
                    }
                }
            }
        }
        count++;
    }
    
    //delete item
    template<class T>
    void sortedList<T>::deleteItem(const T& itemToRemove){
        node<T> *currentNode;
        node<T> *lastNode;
        node<T> *nextNode;
        
        currentNode = first;
        
        int i =0;
        int j = count;
        bool removed = false;
        while(i < count){
            if(currentNode->item == itemToRemove && removed == false){
                if(i == 0 && count == 1){
                    currentNode = NULL;
                    first = NULL;
                    last = NULL;
                    //count = 0;
                }
                else if(i == count - 2){
                    lastNode->link = NULL;
                    currentNode = NULL;
                    last = lastNode;
                    //count--;
                }
                else if(i == 0 && j > 1){
                    nextNode = currentNode->link;
                    first = nextNode;
                    currentNode->link = NULL;
                    currentNode = NULL;
                    
                }
                else{

                    lastNode->link = currentNode->link;
                    currentNode->link = NULL;
                    currentNode = NULL;
                    
                }
                count--;
                removed = true;
                i = count;
            }
            else{
                i++;
                lastNode = currentNode;
                currentNode = currentNode->link;
            }
            
        }
        if(removed == false){
            throw logic_error("Item Not Found In List");
        }
        
    }
    
    //deleteAll
    template<class T>
    void sortedList<T>::deleteAll(T itemToRemove){
        node<T> *currentNode;
        node<T> *lastNode;
        node<T> *nextNode;
        
        currentNode = first;
        
        int i = 0;
        int j = count;
        bool removed = false;
//         for(int i= 0; i < j;i++){
        while(currentNode != last){
            
            if(currentNode->item == itemToRemove && currentNode != last){
                
                if(i == 0 && j == 1){
                    currentNode = NULL;
                    first = NULL;
                    last = NULL;
                    
                }
//                 else if(i == j - 2){
//                     
//                     lastNode->link = NULL;
//                     currentNode = NULL;
//                     last = lastNode;
//                     
//                 }
                else if(i == 0 && j > 1){
                    
                    nextNode = currentNode->link;
                    first = nextNode;
                    currentNode->link = NULL;
                    currentNode = NULL;
                    
                }
                else{
                    
                    lastNode->link = currentNode->link;
                    cerr << currentNode->item << " removed in loop" << endl;
                    currentNode = currentNode->link;
                    cerr << currentNode->item << "  in loop" << endl;
                }
                count--;
                removed = true;
                
                
                //lastNode = currentNode;
                cerr << currentNode->item << "old in loop" << endl;
                //currentNode = currentNode->link;
                cerr << currentNode->item << "new in loop" << endl;
                
                
            }
            
            else{
                if(currentNode != NULL){
                    cerr<<"node != null "<<currentNode->item<<endl;
                
                    lastNode = currentNode;
                    currentNode = currentNode->link;
                    
                }
            }
            i++;
        }
        if(currentNode == last && currentNode->item == itemToRemove){
            lastNode->link = NULL;
            last = lastNode;
            cerr << currentNode->item << " last to rm loop" << endl;
            currentNode = NULL;
            removed = true;
        }
        if(removed == false){
            throw logic_error("Item Not Found In List");
        }
    }
    
    //valueAt
    template<class T>
    T& sortedList<T>::valueAt(int index) const{
        node<T> *currentNode;
        currentNode = first;
        if(index < count && index>=0){
            for(int i =0; i < index; i++){
                currentNode = currentNode->link;
                
            }
            return currentNode->item;
        }
        else{throw out_of_range("Index Out Of Range");}
    }
                
    //inList
    template<class T>
    bool sortedList<T>::inList(int itemIn) const{
        bool found = false;
        node<T> *currentNode;
        currentNode = first;
        
        for(int i =0; i < count; i++){
            if(currentNode->item == itemIn){
                return true;
            }
            else{
                currentNode = currentNode->link;
            }
            
            }

        
        
        return found;
    }
    
    //traverse
    template<class T>
    void sortedList<T>::traverse(traverseType input){
        node<T> *currentNode;
        currentNode = first;
        
        if(input == visit){
            for(int i =0; i < count; i++){
            
                cout << currentNode->item << "/";
                currentNode = currentNode->link;
            
            }
        }
        else{
            
            for(int i =0; i < count; i++){
                currentNode = currentNode->link;
                cout << currentNode->item << "/";
                currentNode = currentNode->link;
            
            }
        }
    }
    
    //merge
    template<class T>
    void sortedList<T>::merge(const sortedList<T>& list1){
        node<T> *currentNode;
        node<T> *newNode;
        
        node<T> *nextNode;
        
        newNode = new node<T>;
        nextNode = new node<T>;
        
        bool found = false;
        
        
        currentNode = first;
        
        newNode = new node<T>;
        newNode->link = NULL;
        
        for(int i =0; i < list1.count; i++){
            this->insertItem(list1[i]);
        }
        
//         if(list1.getFormat() == ASCENDING){
//             for(int i =0; i < count; i++){
//                 
//                 newNode->item = list1[i];
//             
//                 
//                 
//                 if(newNode->item <= currentNode->item){
//                     
//                     newNode->link = currentNode;
//                     first = newNode;
//                 }
//                 else if(newNode->item >= currentNode->item && currentNode->link == NULL){
//                             currentNode->link = newNode;
//                             last = newNode;
//                 }
//                 else{
//                     while(currentNode != NULL && found == false){
//                         if(currentNode == last){
//                             currentNode->link = newNode;
//                             last = newNode;
//                             found = true;
//                         }
//                         else{
//                             nextNode = currentNode->link;
//                         }
//                         
//                         if(currentNode->item <= newNode->item && nextNode->item >= newNode->item){
//                             
//                             newNode->link = currentNode->link;
//                             currentNode->link = newNode;
//                             found = true;
//                         }
//                         else{
//                             currentNode = currentNode->link;
//                         }
//                     
//                     }
//                 }
//             
//             }
//         }
//         else{
//             for(int i =0; i < count; i++){
//             newNode->item = list1[i];
//             if(newNode->item >= currentNode->item){
//                     
//                     newNode->link = currentNode;
//                     first = newNode;
//                 }
//                 else if(newNode->item <= currentNode->item && currentNode->link == NULL){
//                             currentNode->link = newNode;
//                             last = newNode;
//                 }
//                 else{
//                     while(currentNode != NULL && found == false){
//                         if(currentNode == last){
//                             currentNode->link = newNode;
//                             last = newNode;
//                             found = true;
//                         }
//                         else{
//                             nextNode = currentNode->link;
//                         }
//                         
//                         if(currentNode->item >= newNode->item && nextNode->item <= newNode->item){
//                             
//                             newNode->link = currentNode->link;
//                             currentNode->link = newNode;
//                             found = true;
//                         }
//                         else{
//                             currentNode = currentNode->link;
//                         }
//                     
//                     }
//                 }
// 
//         }
//         }
    }
    
    //removeDuplicates
    template<class T>
    void sortedList<T>::removeDuplicates(){
//         <T> numbers[50] = {};
//         node<T> *currentNode;
//         currentNode = first;
//         for(int i =0; i < count; i++){
// //             if(currentNode->item 
// //             this->insertItem(list1[i]);
//         }
    }
    
    //setter for format
    template<class T>
    void sortedList<T>::setOrder(order_Format f) {
        format = f;
        sortedList<T> tmpList(f);
        
        node<T> *currentNode;
        currentNode = first;
        
        for(int i =0; i < count; i++){
            tmpList.insertItem(currentNode->item);
            currentNode = currentNode->link;
        }
        currentNode = first;
        for(int i =0; i < count; i++){
           currentNode->item = tmpList[i];
            currentNode = currentNode->link;
        }
        //this-> = tmpList;
    }

    //default for the format
    template<class T>
    order_Format sortedList<T>::format=ASCENDING;

    //getter for format
    template<class T>
    order_Format sortedList<T>::getFormat() {
        return format;
    }
    
    //overide for =
    template<class T>
    const sortedList<T>& sortedList<T>::operator = (const sortedList<T>& otherList){
        if(this != &otherList){
            copySortedList(otherList);
        }
        return *this;
    }


}
#endif
