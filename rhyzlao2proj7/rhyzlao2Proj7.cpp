#include "ArchipelagoExpedition.h"
#include <iostream>

int main (int argc, char** argv)
{
    FILE* inFile = stdin;

    ArchipelagoExpedition IslandData;

    IslandData.showCommands();
    printf ("\nEnter commands at blank line\n");
    printf ("(No prompts are given because of f command)\n");
    IslandData.processCommandLoop (inFile);

    printf ("Goodbye\n");
    return 1;
}
