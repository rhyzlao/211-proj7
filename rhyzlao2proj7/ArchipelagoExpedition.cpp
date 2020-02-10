#include "ArchipelagoExpedition.h"

ArchipelagoExpedition::ArchipelagoExpedition()
    {
        Travelsize = 10;
        fileList = new MyList;
        myQueue =  new MyList;
        myStack = new MyList;
        landho = new Island[Travelsize + 1];

        for(int i = 1; i< Travelsize; i++){
            landho[i].setNumba(i);
        }

    }
    
ArchipelagoExpedition::~ArchipelagoExpedition(){
    	delete [] landho;
    	delete fileList;
        delete myQueue;
        delete myStack;
	}


MyList* ArchipelagoExpedition::breadthFirstSearch (int x, int y)
{
    //initialize
    for(int i = 1; i < Travelsize + 1; i++){
        landho[i].setPrev(-1);
    }

    myQueue->setHead();
    myQueue->pushNode(x);

    if(bfs(y) == false){
        cout << "You can NOT get from Island " << x << " to Island " << y << " in one or more trips" << endl;
        return myQueue;
    }
    else{
        cout << "You can get from Island " << x << " to Island " << y << " in one or more trips" << endl;
        myStack->setHead();
        int currrentIsland = y;
        myStack->pushFront(currrentIsland);
        do{
            currrentIsland = landho[currrentIsland].getPrev();

            myStack->pushFront(currrentIsland);
        }while(currrentIsland != x);
    }
    return myStack;
}

bool ArchipelagoExpedition::bfs(int b){

    while (myQueue->isEmpty() != true)
    {
        int a = myQueue->getFront();
        myQueue->removeFront();

        int size = landho[a].getAdjList()->getsize();

        for(int i = 0; i < size; i++) {

            int c = landho[a].getAdjList()->getNthNode(i);
            if(landho[c].getPrev() == -1){
                landho[c].setPrev(a);
                if(c == b){
                    return true;
                }
                myQueue->pushNode(c);
            }
        }
    }
    return false;
}

void ArchipelagoExpedition::depthFirstSearchHelper(int s, int t)
    {
        //initialize
        for(int i = 1; i < Travelsize + 1; i++){
            landho[i].NotVisited();
        }
        if (dfs(s, t) == true)
            cout << "You can get from Island " << s << " to Island " << t << " in one or more trips" << endl;
        else
            cout << "You can NOT get from Island " << s << " to Island " << t << " in one or more trips" << endl;
    }

bool ArchipelagoExpedition::dfs (int s, int t)
    {
        MyList* tmpList = landho[s].getAdjList();

        for (int i = 0; i < tmpList->getsize(); i++)
        {
            int id = tmpList->getNthNode(i);
            if (id == t)
                return true;
            // check if Island id is unvisited
            if ( landho[id ].isVisited() == false )
            {
                //mark Island id as visited
                landho[id ].setVisted();
                if ( dfs (id, t) == true )
                    return true;
            }
        }
        return false;
    }

void ArchipelagoExpedition::processCommandLoop (FILE* inFile)
    {
        char  buffer[300];
        char* input;

        input = fgets ( buffer, 300, inFile );   
        while (input != NULL)
        {
            // process each line of input using the strtok functions
            char* command;
            command = strtok (input , " \n\t");

            printf ("*%s*\n", command);

            if ( command == NULL )
                printf ("Blank Line\n");

            else if ( strcmp (command, "q") == 0){
            	this->~ArchipelagoExpedition();
                exit(1);
            }

            else if ( strcmp (command, "?") == 0)
                showCommands();

            else if ( strcmp (command, "t") == 0)
                doTravel();

            else if ( strcmp (command, "r") == 0)
                doResize();

            else if ( strcmp (command, "i") == 0)
                doInsert();

            else if ( strcmp (command, "d") == 0)
                doDelete();

            else if ( strcmp (command, "l") == 0)
                doList();

            else if ( strcmp (command, "f") == 0)
                doFile();
			
			else if ( strcmp (command, "s") == 0)
                doShortestPath();

            else if ( strcmp (command, "#") == 0)
                 ;

            else
                printf ("Command is not known: %s\n", command);

            input = fgets ( buffer, 300, inFile );   
        }
    }

void ArchipelagoExpedition::showCommands()
    {
        printf ("The commands for this project are:\n");
        printf ("  q \n");
        printf ("  ? \n");
        printf ("  # \n");
        printf ("  t <int1> <int2> \n");
        printf ("  r <int> \n");
        printf ("  i <int1> <int2> \n");
        printf ("  d <int1> <int2> \n");
        printf ("  l \n");
        printf ("  f <filename> \n");
        printf ("  s <int1> <int2> \n");
        
    }

void  ArchipelagoExpedition::doShortestPath(){
		int val1 = 0;
        int val2 = 0;

        char* next = strtok (NULL, " \n\t");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val1 = atoi ( next );
        if ( val1 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }

        next = strtok (NULL, " \n\t");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val2 = atoi ( next );
        if ( val2 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }

		
    	if(val1 < 1 || val1 > Travelsize || val2 < 1 || val2 > Travelsize){
       			 cout << "Not in range. Range = 1 - " << Travelsize << endl;
        		 return;
        	}

		printf ("Performing the Shorthest Path Command from %d to %d\n",
                val1, val2);

        MyList* shortestPath = breadthFirstSearch(val1, val2);
        shortestPath->showList();
        cout << endl;
	
}

void ArchipelagoExpedition::doTravel()
    {
        int val1 = 0;
        int val2 = 0;

        // get an integer value from the input
        char* next = strtok (NULL, " \n\t");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val1 = atoi ( next );
        if ( val1 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }

        // get another integer value from the input
        next = strtok (NULL, " \n\t");
        if ( next == NULL )
        {
            printf ("Integer value expected\n");
            return;
        }
        val2 = atoi ( next );
        if ( val2 == 0 && strcmp (next, "0") != 0)
        {
            printf ("Integer value expected\n");
            return;
        }

		
    	if(val1 < 1 || val1 > Travelsize || val2 < 1 || val2 > Travelsize){
       			 cout << "Not in range. Range = 1 - " << Travelsize << endl;
        		 return;
        	}
		
		printf ("Performing the Travel Command from %d to %d\n",
                val1, val2);

        depthFirstSearchHelper(val1, val2);

    }

void ArchipelagoExpedition::doResize()
    {
    	
        int val1 = 0;

		//get user input
        char* next = strtok (NULL, "\n\t");
        if (next == NULL){
            cout << "Integer value expexted" << endl;
            return;
        }

        val1 = atoi(next);

        if(val1 == 0 && strcmp(next, "0") != 0){
            cout << "Integer value expexted" << endl;
            return;
        }
	
	//update size
        if(val1 >= 1){
            cout << "Performing the Resize Command with " << val1 << endl;
            delete [] landho;
            Travelsize = val1;
            landho = new Island[Travelsize + 1];

            for(int i = 0; i < Travelsize + 1; i++){
                landho[i].setNumba(i);
            }
            cout << "Size is = " << Travelsize << endl;
        }
		// give error 
        else{
            cout << "Size should be at least 1" << endl;
            return;
        }




    }

void ArchipelagoExpedition::doInsert()
    {
        int port1= 0 , port2 = 0;
        
        char* next = strtok (NULL, " \n\t");
            if ( next == NULL )
            {
                printf ("Integer value expected\n");
                return;
            }
            port1 = atoi ( next );
            if ( port1 == 0 && strcmp (next, "0") != 0)
            {
                printf ("Integer value expected\n");
                return;
            }

            next = strtok (NULL, " \n\t");
            if ( next == NULL )
            {
                printf ("Integer value expected\n");
                return;
            }
            port2 = atoi ( next );
            if ( port2 == 0 && strcmp (next, "0") != 0)
            {
                printf ("Integer value expected\n");
                return;
            }
            
             if(port1 < 1 || port1 > Travelsize || port2 < 1 || port2 > Travelsize){
       			 cout << "Not in range. Range = 1 - " << Travelsize << endl;
        		 return;
        	}

            cout << "Performing the insert command from " << port1 << " to " << port2 << endl;
            //insert 
            landho[port1 ].insert(port2);
            


    }

void ArchipelagoExpedition::doDelete()
    {
        int port1= 0 , port2 = 0;
	
        char* next = strtok (NULL, " \n\t");
            if ( next == NULL )
            {
                printf ("Integer value expected\n");
                return;
            }
            port1 = atoi ( next );
            if ( port1 == 0 && strcmp (next, "0") != 0)
            {
                printf ("Integer value expected\n");
                return;
            }

            next = strtok (NULL, " \n\t");
            if ( next == NULL )
            {
                printf ("Integer value expected\n");
                return;
            }
            port2 = atoi ( next );
            if ( port2 == 0 && strcmp (next, "0") != 0)
            {
                printf ("Integer value expected\n");
                return;
            }

            cout << "Deleting from " << port1 << " to " << port2 << endl;
          
            landho[port1].deleting(port2);

    }

void ArchipelagoExpedition::doList()
    {
        cout << "Island Connections" << endl;
		
		//print
        for(int i = 1; i < Travelsize + 1; i++){
            cout << i << "->";
            landho[i].show();
            cout << endl;
        }
}
 
int ArchipelagoExpedition::countAsciiValues(char* afilename){
        int count = 0;
        for(unsigned int i = 0; i < strlen(afilename); i++){
            count = count + afilename[i];
        }         
        return count;
}

void ArchipelagoExpedition::doFile(){

        // get a filename from the input
        char* fname = strtok (NULL, " \n\t");
        if ( fname == NULL )
        {
            printf ("Filename expected\n");
            return;
        } 
        int value = countAsciiValues(fname);
		
		// file is not being used
        if(fileList->contains(value) == true ){       	
            cout << "File is already in use" << endl;
            return;
        }
		
		// open 
        FILE* inputFile = fopen(fname, "r");
   
        if(inputFile == NULL){
            cout << "Cannot open the file" << endl;
            return;
        }
	
		printf ("Performing the File command with file: %s\n", fname);

        fileList->pushNode(value);
        processCommandLoop(inputFile);
        fclose(inputFile);
        fileList->popNode(value);
        
}



