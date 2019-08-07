#ifndef _ARRAY_H_
#define _ARRAY_H_

namespace ArrayNameSpace{

template <class t>
class Array{

public:
    //default constructor
    //Array();
    
    //constructor for a single int
    explicit Array(int size=0);
    
    //Constructor for offset index
    Array(int startIndex, int endIndex);
    
    // destructor
    ~Array();
    
    
    //copy constructor
    Array(const Array&);
    
    //operator =
    const Array& operator = (const Array&);
    
    // method - override ==
    // description - override ==
    // preconditions - must be a valid object
    // postconditions -  none
    // method input - none
    // method output - bool
    bool operator == (const Array&) const;
    
    // method - override !=
    // description - override !=
    // preconditions - must be a valid array
    // postconditions -  none
    // method input - array
    // method output - bool
    bool operator!=(const Array&) const;
    
    
    // method - override <
    // description - override <
    // preconditions - must be a valid array
    // postconditions -  none
    // method input - array
    // method output - bool
    bool operator<(const Array&) const;
    
    // method - override >
    // description - override >
    // preconditions - must be a valid array
    // postconditions -  none
    // method input - array
    // method output - bool
    bool operator>(const Array&) const;
    
    // method - override <=
    // description - override <=
    // preconditions - must be a valid array
    // postconditions -  none
    // method input - array
    // method output - bool
    bool operator<=(const Array&) const;
    
    // method - override >=
    // description - override >=
    // preconditions - must be a valid object
    // postconditions -  none
    // method input - none
    // method output - bool
    bool operator >= (const Array&) const;
    
    //getter for size
    int Size() const;
    
    //operator []
    t& operator[](int index);
    
    //const operator[]
    const t& operator[](int index) const;
    
    //reverse
    Array<t> reverse() const;
    
    // method - Ascending
    // description - Ascending sort
    // preconditions - must have a valid object
    // postconditions -  none
    // method input - none
    // method output - a sorted array
    Array<t> Ascending() const;
    
    // method - Descending
    // description - Descending sort
    // preconditions - must have a valid object
    // postconditions -  none
    // method input - none
    // method output - a sorted array
    Array<t> Descending() const;
    
    //traversal
    void traversal(void (*) (t&));
    
    //add to the end of the array
    void add(t num);
    //return and remove the end of the array
    t remove();
    
    //getStartIndex
    int getStartIndex() const;
    
    //setStartIndex
    void setStartIndex(int newIndex);
    
    // method - resize
    // description - resizes an array
    // preconditions - must have a valid object
    // postconditions -  changes the array size
    // method input - int
    // method output - none
    void Resize(int newSize);
    
private:
    //array Size
    int arraySize;
    
    //startIndex
    int startIn;
    
    //# elements in the array
    int count;
    
    //the array
    t *theArray;

};

// method - default constructor
// description - constructor for no input 
// preconditions - none
// postconditions -  creates and initializes a new Array
// method input - none
// method output - new Array
// template <class t>
// Array<t>::Array(){
//     theArray = new t[];
//     count = 0;
//     arraySize = 0;
// }


// method - default constructor
// description - constructor for no input 
// preconditions - none
// postconditions -  creates and initializes a new Array
// method input - int
// method output - new Array
template <class t>
Array<t>::Array(int num){
    theArray = new t[num];
    count = 0;
    arraySize = num;
}

// method - constructor for offset index
// description - constructor for index input 
// preconditions - none
// postconditions -  creates and initializes a new Array
// method input - int, int
// method output - new Array
template <class t>
Array<t>::Array(int startIndex, int endIndex){
    
    int size = endIndex - startIndex;
    startIn = startIndex;
    arraySize = endIndex - startIndex;
    theArray = new t[size];
    count = 0;
}

// method - default deconstructor
// description - deconstructor 
// preconditions - must have a valid Array to delete
// postconditions -  deletes an array
// method input - none
// method output - none
template <class t>
Array<t>::~Array(){
    delete [] theArray;
    theArray = NULL;
}

// method - copy constructor
// description - copies an Array
// preconditions - must have a valid Array to copy
// postconditions -  creates a new Array
// method input - old Array
// method output - new Array
template <class t>
Array<t>::Array(const Array<t>& array){
    theArray = new t[array.arraySize];
    count = array.count;
    arraySize = array.arraySize;
    startIn = array.startIn;
    for (int i=0; i<=count; i++){
        theArray[i] = array.theArray[i];
    }
}

// method - override for operator =
// description - overides =
// preconditions - bust have a valid Array
// postconditions -  creates a copy of an array
// method input - none
// method output - Array
template <class t>
const Array<t>& Array<t>::operator = (const Array<t>& array){
    if (&array != this){
        delete [] theArray;
        theArray = new t[array.arraySize];
        count = array.count;
        arraySize = array.count;
        for(int i =0; i<=count; i++)
        {
            theArray[i] = array[i];
        }
    }
    return *this;
}


// method - add
// description - adds an element to the array 
// preconditions - must have a valid array
// postconditions -  item added to the array
// method input - item of type
// method output - none
template <class t>
void Array<t>::add(t num)
{
    theArray[count] = num;
    count++;
}


// method - remove
// description - removes an element from the array
// preconditions - must have a valid array
// postconditions -  none
// method input - index to be removed
// method output - none
template <class t>
t Array<t>::remove()
{
    count--;
    return theArray[count];
}

// method - traversal
// description - traversal of the array
// preconditions - must have a valid object
// postconditions -  none
// method input - none
// method output - none
template <class t>
void Array<t>::traversal(void (*f)(t&))
{
   for (int i=0; i<count; i++)
      f(theArray[i]);
}

// method - getStartIndex()
// description - getter for startIndex
// preconditions - must have a valid object
// postconditions -  none
// method input - none
// method output - int
template <class t>
int Array<t>::getStartIndex() const
{
   return this-> startIn;
}

// method - setStartIndex()
// description - setter for startIndex
// preconditions - must have a valid object
// postconditions -  sets the startIndex
// method input - int
// method output - none
template <class t>
void Array<t>::setStartIndex(int newIndex)
{
    this-> startIn = newIndex;
}

// method - operator []
// description - overloads []
// preconditions - must have a valid array
// postconditions -  none
// method input - int
// method output - the Array[index]
template <class t>
t& Array<t>::operator[](int index)
{
    
    int tmp = getStartIndex();
    
    
    if(index < tmp || index > (tmp + this->Size()))
    {
        throw std::out_of_range ("Index Out Of Range");
    }
    
    return theArray[index-tmp];
}

// method - const operator []
// description - [] for non mutator
// preconditions - must have a valid array
// postconditions -  none
// method input - int
// method output - array[index]
template <class t>
const t& Array<t>::operator[](int index) const{
    int tmp = getStartIndex();
    if(index < tmp || index > tmp + this->Size())
    {
        throw std::out_of_range ("Index Out Of Range");
    }
    
    return theArray[index-tmp];
}

// method - Size
// description - getter for size 
// preconditions - must have a valid object
// postconditions -  none
// method input - none
// method output - int
template <class t>
int Array<t>::Size() const 
{
    return this-> arraySize;
}

// method - reverse
// description - returns a reversed array
// preconditions - must have a valid object
// postconditions -  none
// method input - none
// method output - an array
template <class t>
Array<t> Array<t>::reverse() const 
{
    int tmpSize = this->Size;
    Array<t> newArray(tmpSize);
    int tmpIndex = 0;
    for (int i = tmpSize; i >= 0; i--)
    {
        newArray[tmpIndex] = theArray[i];
        newArray.count++;
        tmpIndex++;
    }
    return newArray;
}

// method - Ascending
// description - returns a ascending array
// preconditions - must have a valid object
// postconditions -  none
// method input - none
// method output - a sorted array
template <class t>
Array<t> Array<t>::Ascending() const{
    int i;
    int j;
    int k;
    int n = this.Size();
    int temp;
    
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(this.theArray[i]>this.theArray[j]){
                temp  =this.theArray[i];
                this.theArray[i]=this.theArray[j];
                this.theArray[j]=temp;
                
            }
            
        }
        
    }
    
    
}

// method - Descending
// description - returns a descending array
// preconditions - must have a valid object
// postconditions -  none
// method input - none
// method output - a sorted array
template <class t>
Array<t> Array<t>::Descending() const{
    int i;
    int j;
    int k;
    int n = this.Size();
    int temp;
    
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(this.theArray[i]<this.theArray[j]){
                temp  =this.theArray[i];
                this.theArray[i]=this.theArray[j];
                this.theArray[j]=temp;
                
            }
            
        }
        
    }
    
    
}

// method - override ==
// description - override ==
// preconditions - must be a valid array
// postconditions -  none
// method input - array
// method output - bool
template <class t>
bool Array<t>::operator == (const Array& arrayB) const{
    if(arrayB.Size() != this->Size){
        return false;
    }
    
    else{
        for (int i = 0; i <= arrayB.Size(); i++){
            if (arrayB[i] != this->theArray[i]){
                return false;   
            }
        }
    }
    return true;
    
}

// method - override !=
// description - override !=
// preconditions - must be a valid array
// postconditions -  none
// method input - array
// method output - bool
template <class t>
bool Array<t>::operator!=(const Array& arrayB) const{
    if(this == arrayB){
        return false;
    }
    else{
        return true;
    }
    
}

// method - override >
// description - override >
// preconditions - must be a valid array
// postconditions -  none
// method input - array
// method output - bool
template <class t>
bool Array<t>::operator>(const Array& arrayB) const{
    
    int tmpSize1 = this->Size();
    int tmpSize2 = arrayB.size();
    int smaller;
    if(tmpSize1 == tmpSize2){
        for(int i = 0; i <= tmpSize1; i++){
            if(this->theArray[i] > arrayB[i]){
                return true;
            }
        }
    }
    else if(tmpSize1 > tmpSize2){
        smaller = tmpSize2;
        for(int i = 0; i <= smaller+1; i++){
            if(this->theArray[i] > arrayB[i]){
                return true;
            }
            if(i == smaller+1){
                return true;
            }
        }
    }
    else{
        smaller = tmpSize1;
        for(int i = 0; i <= smaller+1; i++){
            if(this->theArray[i] > arrayB[i]){
                return true;
            }
            if(i == smaller+1){
                return true;
            }
        }
    }
    return false;
    
}

// method - override <
// description - override <
// preconditions - must be a valid array
// postconditions -  none
// method input - array
// method output - bool
template <class t>
bool Array<t>::operator<(const Array& arrayB) const{
    
    int tmpSize1 = this->Size();
    int tmpSize2 = arrayB.size();
    int smaller;
    if(tmpSize1 == tmpSize2){
        for(int i = 0; i <= tmpSize1; i++){
            if(this->theArray[i] < arrayB[i]){
                return true;
            }
        }
    }
    else if(tmpSize1 > tmpSize2){
        smaller = tmpSize2;
        for(int i = 0; i <= smaller; i++){
            if(this->theArray[i] < arrayB[i]){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        smaller = tmpSize1;
        for(int i = 0; i <= smaller; i++){
            if(this->theArray[i] > arrayB[i]){
                return true;
            }
            if(i == smaller+1){
                return true;
            }
        }
    }
    return false;
    
}

// method - override >=
// description - override >=
// preconditions - must be a valid array
// postconditions -  none
// method input - array
// method output - bool
template <class t>
bool Array<t>::operator>=(const Array& arrayB) const{
    if(this == arrayB){
        return true;
    }
    else if(this > arrayB){
        return true;
    }
    else{
        return false;
    }
    
}

// method - override <=
// description - override <=
// preconditions - must be a valid array
// postconditions -  none
// method input - array
// method output - bool
template <class t>
bool Array<t>::operator<=(const Array& arrayB) const{
    if(this == arrayB){
        return true;
    }
    else if(this < arrayB){
        return true;
    }
    else{
        return false;
    }
    
}


// method - resize
// description - resizes an array
// preconditions - must have a valid object
// postconditions -  changes the array size
// method input - int
// method output - none
template <class t>
void Array<t>::Resize(int newSize)
{
    if (newSize < 0)
    {
        throw std::out_of_range("Index Less Then 0");
    }
    else
    {
        
    Array<t> newArray(newSize);
     
    for (int i = 0; i<newSize; i++)
    {
        theArray[i] = theArray[i];
        //newArray[i] = theArray[i];
        //newArray.count++;
    }
    
    //theArray = newArray.theArray;
    
    //newArray.count = newSize;
     //newArray.arraySize = newSize;
     //newArray.startIn = startIn;
     //count = newSize;
 //         int tmpcount = count;
//         for(int  i = tmpcount; i > newSize; i--){
//             theArray[i] = NULL;
//             count--;
//             
//         }
     //Array<t> newArray = new Array<t>(;   
//      delete [] theArray;
//      
//      theArray = new t[newSize];
//      
//      for (int i = 0; i<=newSize; i++){
//          theArray[i] = newArray[i];
//      }
     
    }
}





}
#endif
