#include "MyNode.h"

MyNode::MyNode(int ID){
        nodeID = ID;
        pNext = NULL;
}

void MyNode::setNext(MyNode* node){
        pNext = node;

}

int MyNode::getId(){
        return nodeID;
}

MyNode* MyNode::getNext(){
        return pNext;
}

