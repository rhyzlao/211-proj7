#ifndef PROJECT6_ArchipelagoExpedition_H
#define PROJECT6_ArchipelagoExpedition_H
#include <cstring>
#include <string>
#include <iostream>
#include "Island.h"
#include "MyList.h"

class ArchipelagoExpedition
{
private:
    int Travelsize;
    Island* landho;
    MyList* myQueue; 
    MyList* myStack; 
    MyList* fileList;

public:
    ArchipelagoExpedition();
    ~ArchipelagoExpedition();
    void depthFirstSearchHelper(int s, int t);
    bool dfs (int s, int t);
    void processCommandLoop (FILE* inFile);
    void showCommands();
    void doTravel();
    void doShortestPath();
    MyList* breadthFirstSearch(int x, int y);
    bool bfs(int b);
    void doResize();
    void doInsert();
    void doDelete();
    void doList();
    int countAsciiValues(char* afilename);
    void doFile();
};
#endif

