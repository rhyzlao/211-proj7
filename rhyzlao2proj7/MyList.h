#ifndef PROJECT6_mylist_H
#define PROJECT6_mylist_H
#include <iostream>
#include "MyNode.h"

class MyList{
private:
    MyNode* phead;
    int size; 

public:
   
    MyList();
    ~MyList();
    MyNode* getHead();
    int getsize();
    int getNthNode(int index);
    void setHead();
    void pushNode(int ID);   
    void pushFront(int ID);
    int getFront();
    void removeFront();
	bool isEmpty();	
    void popNode(int key);
    bool contains(int x);
    void showList();
  
}; 
#endif

