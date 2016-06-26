#pragma once          // same as  include guards below, but non-standard
//#ifndef LINE_H
//#define LINE_H
#include <iostream>     // for ostream
//#include <cstring>

using std::ostream;
using std::istream;

class Line
{
private:
	
	char* linePtr;// { nullptr };                    // pointer to dynamic memory

	int currentCapacity;
	
	const int MINIMUM_CAPACITY;
		
	const int MAXIMUM_CAPACITY;

	int availableIndex;

	



public:

    void resize (int);
	
	Line();									// default constructor
	
	Line(char*);							// a constructor overload
	
    Line(char);								// constructor with one char

	char* cstr();
	
    Line(const Line&);						// copy constructor

    ~Line();                                // destructor

	void print() const; // const means that print does not modify *this

	friend ostream& operator<<(ostream& out, const Line& thatLine);		// assignment operator overload

	friend istream& operator>>(istream& in, Line& thatLine);

	const Line& operator=(const Line&);			// assignment operator overload
	
		
	bool empty();

	bool full();

	const int capacity ();

	void push_back (const char& someChar);

	
	void pop_back ();

	//const int cstr();

	//int length();


	

	

	

	

	
	
   
	
	
	
	    
	
    // we did not write this member function in class
   
};

//#endif //line.h

