#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>

using namespace std;

enum weightFormat {WEIGHTED,UNWEIGHTED};
enum directionFormat {DIRECTED,UNDIRECTED};

//define the vertex
template <class T>
class vertex{
    public:
        // method - constructor
        // description - constructor
        // preconditions - none
        // postconditions -  creates a vertex
        // method input - none
        // method output -none
        vertex(const T&);
        
        // method - getItemName
        // description - getter for itemName
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - none
        // method output -itemName
        string getItemName() const;
        
        // method - addEdge
        // description - adds an edge
        // preconditions - must have a valid vertex
        // postconditions -  creates an edge
        // method input - two ints
        // method output -none
        void addEdge(const int& dest,const int& w);
        
        // method - operator ==
        // description - overrides ==
        // preconditions - must have a valid object
        // postconditions -  none
        // method input - string
        // method output - bool
        bool operator==(const string& tmp) const;
        
        // method - output
        // description - outputs a vertex
        // preconditions - must have a valid vertex
        // postconditions -  none
        // method input - vertex<T>
        // method output - none
        void output(const vertex<T>&);
        
  
    private:
        T itemName;
        vector<vector<int>> edgeList;
    
};

//constructor for vertex
template <class T>
vertex<T>::vertex(const T& vName){
    itemName = vName;
    //edgeList = vector<vector<int>>;
}

//getItemName
template<class T>
string vertex<T>::getItemName() const{
    string name = itemName.getName();
    //return itemName.getName();
    return name;
}

//addEdge
template<class T>
void vertex<T>::addEdge(const int& dest, const int& w){
    vector<int> newEdge = new vector<int>[dest,w];
    vector<T>::push_back(newEdge);
}

//==
template<class T>
bool vertex<T>::operator==(const string& tmp) const
{
    return itemName.getName()==tmp;
}

// method - <<
// description - overrides <<
// preconditions - must have a valid vertex
// postconditions -  overrides <<
// method input - ostream&, vertex&
// method output -ostream
template<class T>
ostream& operator  << (ostream&, const vertex<T>&);

// override << for vertex
template <class T>
ostream& operator << (ostream& out,const vertex<T>& v)
{
    out << v.getItemName();
    
    //out << v.outputEdgeList();
    return out;
}

//output
template<class T>
void vertex<T>::output (const vertex<T>& v){
    cout << v.getItemName();
    
    //out << v.outputEdgeList();
    string out = "";
//     typename vector<T>::const_iterator p;
//     for (p= edgeList.begin(); p!= edgeList.end(); p++){
//        out = *p.toString();
//     }
    cout << out << endl;
    
}

//addEdge
// template<class T>
// void vertex<T>::addEdge(const int& dest, const int& w){
//     vector<int> tmp = vector<int>[dest,w];
//     edgeList.push_back(tmp);
// }


//define edge
template<class T>
class edge : public vector<T>{
    vector<int> edgeinfo;
};

//constructor for edge
// template <class T>
// edge<T>::edge(const T& edgeD, const T& edgeW){
//     itemName = vName;
//     //edgeList = new list<T>;
// }

//define the class
template <class T>
class Graph {
    
public:
    // method - constructor
    // description - constructor
    // preconditions - none
    // postconditions -  creates a Graph
    // method input - none
    // method output -none
    Graph(weightFormat,directionFormat);
    
    // method - constructor
    // description - constructor
    // preconditions - none
    // postconditions -  creates a Graph
    // method input - none
    // method output -none
    Graph(directionFormat,weightFormat);
    
    // method - deconstructor
    // description - destroys an object
    // preconditions - must have a valid target
    // postconditions -  deconstructs an object
    // method input - none
    // method output - none
    ~Graph();
    
    // method - copy constructor
    // description - copies a Graph
    // preconditions - must have a valid Graph
    // postconditions -  creates a copy
    // method input - a Graph
    // method output - a new copy
    Graph(const Graph&);
    
    // method - destroy
    // description - destroys a Graph
    // preconditions - must have a valid Graph
    // postconditions -  destroys a Graph
    // method input - none
    // method output -none
    void destroy();
    
    // method - isEmpty
    // description - returns true if the Graph is empty
    // preconditions - must have a valid Graph
    // postconditions -  none
    // method input - none
    // method output -bool
    bool isEmpty();
    
    // method - isFull
    // description - checks if the Graph is full
    // preconditions - must have a valid Graph
    // postconditions -  none
    // method input - none
    // method output - bool
    bool isFull();
    
    // method - insertVertex
    // description - inserts a new vertex if its not already there
    // preconditions - must have a valid Graph
    // postconditions -  new vertex added
    // method input - item of type T
    // method output - none
    void insertVertex(const T&);
    
    // method - deleteVertex
    // description - deletes a vertex if found
    // preconditions - must have a valid Gra[h
    // postconditions -  none
    // method input - item of type T
    // method output - none
    void deleteVertex(const T&);
    
    // method - insertEdge
    // description - inserts an edge if its not already in the Graph
    // preconditions - must have a valid Graph
    // postconditions -  new edge added
    // method input - int list of two ints
    // method output - none
    void insertEdge(const T&, const T&, const int&);
    
    // method - deleteEdge
    // description - removes an edge if found
    // preconditions - must have a valid Graph
    // postconditions -  item removed from the Graph
    // method input - item to be removed
    // method output - none
    void deleteEdge(const T&, const T&);
    
    // method - edgeCount
    // description - returns the number of edges
    // preconditions - must have a valid Graph
    // postconditions -  none
    // method input - none
    // method output - int
    int edgeCount() const;
    
    // method - vertexCount
    // description - returns the number of vertex in the Graph
    // preconditions - must have a valid graph
    // postconditions -  none
    // method input - none
    // method output -none
    int vertexCount()const;
    
    //void insert(const T&);
    
    // method - isAdjacentTo
    // description - returns true if there is an edge to a given vertex
    // preconditions - must have a valid Graph
    // postconditions -  none
    // method input - vertex
    // method output - bool
    bool isAdjacentTo(const T&, const T&);
    
    // method - edgeWeight
    // description - returns the edge Weight
    // preconditions - must have a valid Graph
    // postconditions -  none
    // method input - none
    // method output -int
    int edgeWeight(const T&, const T&);
    
    // method - traverse
    // description - traverses the Graph
    // preconditions - must have a valid Graph
    // postconditions -  none
    // method input - none
    // method output - none
    void traverse(void (*) (T&));
    
    // method - dump
    // description - outputs the vertex and edges of the Graph
    // preconditions - must have a valid Graph
    // postconditions -  none
    // method input - none
    // method output - none
    void dump()const;
    
    // method - 
    // description - 
    // preconditions - 
    // postconditions -  
    // method input - 
    // method output -
    int getGraphSize() const;
    
    // method - const operator []
    // description - overrides [] throws out_of_range exception
    // preconditions - must have a valid object
    // postconditions -  none
    // method input - an index
    // method output - returns a pointer
    const T& operator[](int index) const;
    
    // method - operator ==
    // description - overrides ==
    // preconditions - must have a valid object
    // postconditions -  none
    // method input - string
    // method output - bool
    //bool operator==(const string& tmp) const;
    
private:
    weightFormat wFormat = UNWEIGHTED;
    directionFormat dFormat = UNDIRECTED;
    
    //T VerName;
    //list<list<int>> *edgeList;
    //map<string, list> edgeList;
    vector<vertex<T>> vertexList;
    
    int graphSize;
    

};

template<class T>
Graph<T>::Graph(directionFormat direction,weightFormat weight){
    //name = NULL;
    wFormat = weight;
    dFormat = direction;
    
    //graphSize = 0;
    //edgeList = new vector<vector<int>>;
    //vertexList =  vector<vertex>;
    
}

//destructor
template<class T>
Graph<T>::~Graph(){
    destroy();
}

//destroy()
template<class T>
void Graph<T>::destroy(){
    vertexList.clear();
    //graphSize = 0;
}

//vertexCount
template<class T>
int Graph<T>::vertexCount()const{
    return vertexList.size();
}

//isEmpty
template<class T>
bool Graph<T>::isEmpty(){

    if(vertexList.size() == 0){
        return true;
    }
    else{
        return false;
    }
}

//isFull
template<class T>
bool Graph<T>::isFull(){

    if(vertexList.size() == vertexList.max_size()){
        return true;
    }
    else{
        return false;
    }
}



//insertVertex
template<class T>
void Graph<T>::insertVertex(const T& vName){
    
    bool found = false;
    typename vector<vertex<T>>::iterator p;
    
    
    for (unsigned int i = 0; i < vertexList.size(); i++){
        
        if(vertexList[i].getItemName() == vName.getName()){
            
            found = true;
        }
        else{
            p++;
        }
    }
    
    if(found != true){
        vertex<T> tmp = vertex<T>(vName);
        
        vertexList.push_back(tmp);
        
    }
    else{
        throw invalid_argument("Value Already In the List");
    }
    
}

//deleteVertex
template<class T>
void Graph<T>::deleteVertex(const T& vName){
    bool found = false;
    for (unsigned int i = 0; i < vertexList.size(); i++){
        
        if(vertexList[i].getItemName() == vName){
            vertexList[i].clear();
            found = true;
        }
    
    }
    
    if(found != true){
        throw invalid_argument("Value Is Not In the List");
        
        
    }
    
}

//insertEdge
template<class T>
void Graph<T>::insertEdge(const T& from, const T& dest, const int& w){
    int destination = 0;
    for(unsigned int i = 0; i < vertexList.size(); i++){
        if(vertexList[i].getItemName == from.getName(){
            vertexList[i].addEdge(destination,w);
        }
        else{
            destination++;
        }
    }
    
}

//getGraphSize
template<class T>
int Graph<T>::getGraphSize() const{
    return graphSize;
}


//dump
template<class T>
void Graph<T>::dump()const{
    
    for (unsigned int i = 0; i < vertexList.size(); i++)
      cout << vertexList[i]<< endl;
}

template<class T>
void Graph<T>::traverse(void (*funcPointer)(T&)){
    typename Graph<T>::iterator p;
    for (p=Graph<T>::begin(); p != Graph<T>::end(); p++){
        funcPointer(*p);
    }
}

#endif
