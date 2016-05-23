//#pragma once          // same as  include guards below, but non-standard
#ifndef LINEKEEPER_H
#define LINEKEEPER_H
#include <iostream>     // for ostream

using std::ostream;

class LineKeeper
{
private:
	
	LinkedList::LinkedList& List;                    
	int lineLenght;
	int lineCapacity;

public:

   LineKeeper (const char* fileName);

   void print (int m, int n);
   

};

#endif //linekeeper.h

