proj7: rhyzlao2Proj7.o Island.o ArchipelagoExpedition.o MyList.o MyNode.o
	g++ -o proj7 rhyzlao2Proj7.o Island.o ArchipelagoExpedition.o MyList.o MyNode.o

rhyzlao2Proj7.o: rhyzlao2Proj7.cpp Island.h ArchipelagoExpedition.h MyList.h MyNode.h
	g++ -c rhyzlao2Proj7.cpp 

Island.o: Island.cpp Island.h ArchipelagoExpedition.h MyList.h MyNode.h
	g++ -c Island.cpp

ArchipelagoExpedition.o: ArchipelagoExpedition.cpp Island.h ArchipelagoExpedition.h MyList.h MyNode.h
	g++ -c ArchipelagoExpedition.cpp

MyList.o: MyList.cpp Island.h ArchipelagoExpedition.h MyList.h MyNode.h
	g++ -c MyList.cpp

MyNode.o: MyNode.cpp Island.h ArchipelagoExpedition.h MyList.h MyNode.h
	g++ -c MyNode.cpp

clean: rhyzlao2Proj7.o Island.o ArchipelagoExpedition.o MyList.o MyNode.o
	rm *.o && rm proj7
	