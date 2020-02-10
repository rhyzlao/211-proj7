#include "MyList.h"
#include <iostream>
using namespace std;

// Constructor
MyList::MyList(){
        phead = NULL;
        size = 0;
}

//Destructor
MyList::~MyList(){
        if(phead == NULL){
            return;
        }
        MyNode* temp = NULL;
       
        while (phead != NULL) {
            temp = phead;
            phead = phead->getNext();
            delete temp;
        }
        
        delete phead; // free
        
}

MyNode* MyList::getHead(){
        return phead;
}

int MyList::getsize(){
        return size;
}

int MyList::getNthNode(int index){
        MyNode* temp = phead;

        int count = 0;

        //get index
        while(temp != NULL){

            if(count ==index){
                return temp->getId();
            }
            count++;
            temp = temp->getNext();
        }
		//not found
        return -1;
}

void MyList::setHead(){
    phead = NULL;
}

void MyList::pushNode(int ID){
        MyNode* temp = phead;
        MyNode* addNode = new MyNode(ID);
        size++; 

        if(phead == NULL){
            phead = addNode;
            return;
        }
        //List is not empty
        else{
            while (temp->getNext() != NULL) {
                temp = temp->getNext();
            }
            temp->setNext(addNode);
            return;
        }
    }
    
void MyList::pushFront(int ID){
	MyNode* temp = phead;
	MyNode* addNode = new MyNode(ID);
	size++; 
	
	addNode->setNext(phead);
	phead = addNode;
	
}

int MyList::getFront(){
	return phead->getId();
}

void MyList::removeFront( ){
	
	if(phead != NULL){
		MyNode* temp = phead->getNext();
		delete phead;
		phead = temp;
		size--;
	}
	
}

bool MyList::isEmpty(){
	if(phead == NULL){
		return true;
	}
	else{
		return false;
	}
}

void MyList::popNode(int key){
        MyNode* temp = phead , *prev;

        if (temp != NULL && temp->getId() == key)
        {
            phead = temp->getNext();   
            delete temp;              
            size--;
            return;
        }

        while (temp != NULL && temp->getId() != key)
        {
            prev = temp;
            temp = temp->getNext();
        }

        // If not in list
        if (temp == NULL) return;

        // remove 
        prev->setNext(temp->getNext());

        delete temp;  //free
        size--;
}

bool MyList::contains(int x){
        MyNode* temp = phead;
        while (temp != NULL) {
            if(temp->getId() == x){
                return true;
            }
            temp = temp->getNext();
        }
        return false;
}


void MyList::showList(){
        if(phead == NULL) return;

        MyNode* temp = phead;
        while (temp != NULL) {
            cout << temp->getId() << "->";
            temp = temp->getNext();
        }
}

