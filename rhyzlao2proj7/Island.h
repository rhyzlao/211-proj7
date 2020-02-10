#ifndef PROJECT6_Island_H
#define PROJECT6_Island_H

#include "MyList.h"
using namespace std;

class Island{
private:
   int islandnumba;
   int prev;
   bool visited;
   MyList* adjList;

public:
   Island(int numba);
   Island();
   ~Island();
   bool isVisited();
   void setVisted();
   void NotVisited();
   void setNumba(int numba);
   void setPrev(int l);
   int getislandnumba();
   int getPrev();
   MyList* getAdjList();
   void insert(int numba);
   void deleting(int numba);
   void show();
}; 

#endif

