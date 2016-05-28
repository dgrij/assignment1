// Provides definitions for the declarations made in Line.h
#include <iostream>
//#include <cstring>
#include <string.h>
#include "Line.h"


// Using-declarations
using std::cout;
using std::endl;
using std::strcpy;


Line::Line() : minimumCapacity(100), maximumCapacity(1000) //: linePtr{ new char[1]{ '\0' } }
{
    //minimumCapacity = 100;
	
	linePtr  = new char[minimumCapacity];
	
    linePtr[0] = '\0';

	currentCapacity=strlen(linePtr);
	
	cout<<currentCapacity<<endl;

	//cout<<currentCapacity<<endl;
    cout << "default empty Line ctor" << endl;

}

Line::Line(char* someLine) : minimumCapacity(100), maximumCapacity(1000){

	//minimumCapacity = 100;

	cout<<"Line char* constructor: "<<endl;

	currentCapacity = strlen(someLine);
	
	//minimumCapacity =  minimumCapacity - (currentCapacity+1);

	linePtr = new char[currentCapacity+1];

	
	linePtr[currentCapacity] = '\0';

	availableIndex = strlen(someLine)+1;
	
	strcpy (linePtr,someLine);
	


}

Line::Line(char someChar):minimumCapacity(100), maximumCapacity(1000)
{

	cout<<"Line simple char constructor: "<<endl;
	
	linePtr = new char[minimumCapacity];
	
	linePtr[0] = someChar;

	linePtr[1] = '\0';

	currentCapacity = minimumCapacity;

	availableIndex = 1;

	//minimumCapacity =  minimumCapacity - (currentCapacity+1);

	//linePtr = new char(); // someChar = new char;

//	linePtr = a;
	
	//linePtr = someChar;

	
	//linePtr[currentCapacity+1] = '\0';

	
	
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

Line::Line(const Line& thatLine):minimumCapacity(100), maximumCapacity(1000)
{
    
	cout << "Line copy ctor: " << endl;

    linePtr = new char[strlen(thatLine.linePtr)+1];
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

	
	linePtr[availableIndex++] = someChar;
	
	linePtr[availableIndex] = '\0';

	cout << "push back" << endl;

}


void Line::resize (){

	cout<<currentCapacity<<endl;


	char* tempPtr = new char[2 * currentCapacity];
	
	cout<<availableIndex<<endl;

	



	for (int i = 0; i < this->availableIndex;i++ ) {
	
	tempPtr[i] = linePtr[i];
	
	

	}

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

	else {
	
	linePtr[--availableIndex]='\0';

	cout << "pop back" << endl;
	}
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








/*

Line::Line(char){


}


Line::Line(const Line& thatLine)
{
    cout << "Line copy ctor" << endl;
    linePtr = new char[strlen(thatLine.linePtr) + 1];
    strcpy(linePtr, thatLine.linePtr);
}



Line::Line(char *cstr)
{
    cout << "ctor Line(char *)" << endl;
    linePtr = new char[strlen(cstr) + 1]; // what's the +1 for?
    strcpy(linePtr, cstr);
}


const int cstr(){

	cout << "cstr" << endl;

	return 1;
}

int length(){

	cout << "len" << endl;

	return 1;
}


const int capacity(){

	 cout << "capacity" << endl;

	 return 1;

}







*/