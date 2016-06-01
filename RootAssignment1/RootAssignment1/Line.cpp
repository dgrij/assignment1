// Provides definitions for the declarations made in Line.h
#include <iostream>
//#include <cstring>
#include <string.h>
#include "Line.h"


// Using-declarations
using std::cout;
using std::endl;
using std::strcpy;


Line::Line() : MINIMUM_CAPACITY(100), MAXIMUM_CAPACITY(1000) //: linePtr{ new char[1]{ '\0' } }
{
   	linePtr  = new char[MINIMUM_CAPACITY];
	
	linePtr[0] = '\0';

	availableIndex = 0;

	currentCapacity=MINIMUM_CAPACITY-1;
	
	//cout<<currentCapacity<<endl;

	cout << "default empty Line ctor" << endl;

}

Line::Line(char* someLine) : MINIMUM_CAPACITY(100), MAXIMUM_CAPACITY(1000){

	int tempLength = strlen (someLine);
	
	if (tempLength < MINIMUM_CAPACITY){
	
		linePtr = new char[MINIMUM_CAPACITY];

		strcpy (linePtr, someLine);

		linePtr[tempLength] = '\0';

		availableIndex = tempLength;

		currentCapacity=MINIMUM_CAPACITY-1;
	}

	else if (tempLength < MAXIMUM_CAPACITY)
	{

		linePtr = new char[tempLength+1];
	
		linePtr[tempLength] = '\0';

		availableIndex = tempLength;

		currentCapacity=tempLength;
		

	}

	else { 

		cout<<"Too long you piece of shit, cant save this line  8==============D"<<endl;
	
		//TODO: ADD AN EXCEPTION FOR THIS PIECE OF SHIET

	}
		
}

Line::Line(char someChar):MINIMUM_CAPACITY(100), MAXIMUM_CAPACITY(1000)
{

	cout<<"Line simple char constructor: "<<endl;
	
	linePtr = new char[MINIMUM_CAPACITY];
	
	linePtr[0] = someChar;

	linePtr[1] = '\0';

	currentCapacity = MINIMUM_CAPACITY-1;

	availableIndex = 1;

	
}



// we did not write this member function in class

void Line::print() const // const means that print cannot modify *this
{
	cout<<"Line print method: "<<endl;

	cout << linePtr << endl; // showing off using our own operator<< overload
    //cout << this->linePtr << endl; // same as above
	// cout << (*this).linePtr << endl; // same as above
}

Line::~Line()
{
	std::cerr << "Line dtor: " << endl;
	std::cerr<<linePtr<<std::endl;
    delete[] linePtr;
    linePtr = nullptr;   // defensive programming
}

Line::Line(const Line& thatLine):MINIMUM_CAPACITY(100), MAXIMUM_CAPACITY(1000)
{
    
	cout << "Line copy ctor: " << endl;

    //linePtr = new char[strlen(thatLine.linePtr)+1];

	linePtr = new char[thatLine.currentCapacity+1];

    currentCapacity = thatLine.currentCapacity;

	strcpy(linePtr, thatLine.linePtr);
}

// just a friend member, privileged to see the private members of its parameter m
// note: the keyword 'friend' has no meaning, and should not be used, outside a class

ostream& operator<<(ostream& out, const Line& thatLine)
{
    out << thatLine.linePtr;
    
	return out;
}


istream& operator>>(istream& in, Line& thatLine)
{
    delete[] thatLine.linePtr;
	
	thatLine.linePtr = new char[1000];

	in >> thatLine.linePtr;

	thatLine.availableIndex = strlen(thatLine.linePtr);

	thatLine.currentCapacity = 1000;
	   
	return in;
}




const Line& Line::operator =(const Line & thatLine)
{
    cout << "assignment operator overload (copy assignment)" << endl;
    if (this == &thatLine) return *this; // do nothing on self-assignment
    {
        delete[] linePtr; // release dynamic storage currently used by the LHS operator
        
		linePtr = new char[strlen(thatLine.linePtr) + 1]; // allocate new storage of proper size
        
		strcpy(linePtr, thatLine.linePtr);   // copy
        
		this->currentCapacity=thatLine.currentCapacity;

		this->availableIndex=thatLine.availableIndex;
		
		//strcpy(this->linePtr, m.linePtr); // same as above
    }
    return *this;
}


bool Line::empty(){

	cout<<"Line empty method: "<<endl;

	if (this->linePtr[0] == '\0'){
	
		cout<<"This is an empty line"<<endl;

		return true;
		
	}

	cout<<"This line is not empty, size: "<<this->currentCapacity<<endl;
	
	return false;
	
}


void Line::push_back (const char& someChar){

	if (availableIndex == currentCapacity){
	
	resize(2*currentCapacity);
	
	}
	
	linePtr[availableIndex++] = someChar;
	
	linePtr[availableIndex] = '\0';

	//cout << "push back" << endl;

}


void Line::resize (int newSize){

	cout<<currentCapacity<<endl;


	char* tempPtr = new char[newSize+1];
	
	cout<<availableIndex<<endl;

	
	for (int i = 0; i < this->availableIndex;i++ ) {
	
	tempPtr[i] = linePtr[i];
		
	}

	currentCapacity = newSize;

	tempPtr[availableIndex]='\0';

	delete[] linePtr;

	linePtr = nullptr;
	
	linePtr = tempPtr;

	cout << "resize" << endl;

}

void Line::pop_back (){

	if (availableIndex == 0) { 
		
	cout<<"cant pop any more you piece of shit"<<endl;

	return;
	
	}

	if (availableIndex == currentCapacity/4) {
	
	resize(currentCapacity/2);

	}	
	
	linePtr[--availableIndex]='\0';

	cout << "pop back" << endl;
	
}


bool Line::full(){

	cout<<"Line full method: "<<endl;

	if (this->linePtr[99] == '\0'){
	
		cout<<"This is a full line, size"<<this->currentCapacity<<endl;

		return true;
		
	}

	cout<<"This line is not full, size: "<<this->currentCapacity<<endl;
	
	return false;



	return false;

}




const int Line::capacity(){

	cout<<"Line capacity method, capacity: "<<(this->currentCapacity)<<endl;
	
	return this->currentCapacity;
	 

}


char* Line::cstr(){

	cout << "cstr" << endl;

	return linePtr;
}