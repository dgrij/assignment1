#pragma once          // same as  include guards below, but non-standard
//#ifndef LINE_H
//#define LINE_H
#include <iostream>     // for ostream
//#include <cstring>

using std::ostream;

class Line
{
private:
	
	char* linePtr;// { nullptr };                    // pointer to dynamic memory

	int lineLength;
	
	int lineCapacity;
		
	int availableIndex;



public:

    Line();									// default constructor
	
	Line(char*);							// a constructor overload
	
    //Line(char);								// constructor with one char
	
    Line(const Line&);						// copy constructor

    ~Line();                                // destructor

	void print() const; // const means that print does not modify *this

	friend ostream& operator<<(ostream& out, const Line& thatLine);		// assignment operator overload

	const Line& operator=(const Line&);			// assignment operator overload
	
		
	bool empty();

	const int capacity ();


	//const int cstr();

	//int length();


	//bool full();

	

	//void resize ();

	//void push_back (const char& someChar);

	//void pop_back ();
	
	
   
	
	
	
	    
	
    // we did not write this member function in class
   
};

//#endif //line.h

