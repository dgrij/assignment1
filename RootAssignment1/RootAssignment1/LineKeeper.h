//#pragma once          // same as  include guards below, but non-standard
#ifndef LINEKEEPER_H
#define LINEKEEPER_H
//#include "LinkedList.h"
#include "Line.h"
#include <iostream>     // for ostream
#include <fstream>
#include "LinkedList.h"

using std::ostream;

class LineKeeper : public LinkedList<Line> //to add for linked list ->: public LinkedList<Line>
{

private:
	 
	int lineLenght;
	int lineCapacity;

public:

   LineKeeper (const char* fileName);

   void print (int m, int n);
   

};

#endif //linekeeper.h

