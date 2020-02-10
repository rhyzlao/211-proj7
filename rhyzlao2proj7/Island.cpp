#include "Island.h"
 
   // Constructor
Island::Island(int numba){
       islandnumba = numba;
       prev = -1;
       visited = false;
       adjList = new MyList;
   }

Island::Island(){
       islandnumba = 0;
       prev = -1;
       visited = false;
       adjList = new MyList;
   }
   // Destructor
Island::~Island(){
       islandnumba = 0;
       visited = false;
       delete adjList;
   }

//Manipulating visited
bool Island::isVisited(){
       return visited;
   }

void Island::setVisted(){
       visited = true;
   }

void Island::NotVisited(){
       visited = false;
   }

//manippulate numba
void Island::setNumba(int numba){
       islandnumba = numba;
   }

//set prev
void Island::setPrev(int l){
    prev = l;
    }

int Island::getislandnumba(){
       return islandnumba ;
   }

MyList* Island::getAdjList(){
       return adjList;
   }

int Island::getPrev(){
    return prev;
}

void Island::insert(int numba){
       adjList->pushNode(numba);
   }

void Island::deleting(int numba){
       adjList->popNode(numba);
   }

void Island::show(){
       adjList->showList();
   }

