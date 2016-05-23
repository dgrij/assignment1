// Provides definitions for the declarations made in Line.h
#include <iostream>
//#include <cstring>
#include <string.h>
#include "Line.h"


// Using-declarations
using std::cout;
using std::endl;
using std::strcpy;

Line::Line() //: linePtr{ new char[1]{ '\0' } }
{
    linePtr  = new char[1];
    linePtr[0] = '\0';
	lineLenght=strlen(linePtr);
	//cout<<lineLenght<<endl;
    cout << "default Line ctor" << endl;

}

Line::Line(char* someLine){

	lineLenght = strlen(someLine);
	
	cout<<lineLenght<<endl;
	
	linePtr = new char[lineLenght+1];

	
	//linePtr[lineLenght+1] = '\0';

	strcpy (linePtr,someLine);
	
}

// we did not write this member function in class

void Line::print() const // const means that print cannot modify *this
{
   
	cout << linePtr << endl; // showing off using our own operator<< overload
    //cout << this->linePtr << endl; // same as above
	// cout << (*this).linePtr << endl; // same as above
}







Line::~Line()
{
    //cout << "Line dtor" << endl;
    delete[] linePtr;
    linePtr = nullptr;   // defensive programming
}

Line::Line(const Line& thatLine)
{
    
	cout << "Line copy ctor" << endl;
    linePtr = new char[strlen(thatLine.linePtr) + 1];
    lineLenght = thatLine.lineLenght;
	strcpy(linePtr, thatLine.linePtr);
}

// just a friend member, privileged to see the private members of its parameter m
// note: the keyword 'friend' has no meaning, and should not be used, outside a class

ostream& operator<<(ostream& out, const Line& thatLine)
{
    out << thatLine.linePtr;
    return out;
}


const Line& Line::operator =(const Line & thatLine)
{
    cout << "assignment operator overload (copy assignment)" << endl;
    if (this == &thatLine) return *this; // do nothing on self-assignment
    {
        delete[] linePtr; // release dynamic storage currently used by the LHS operator
        linePtr = new char[strlen(thatLine.linePtr) + 1]; // allocate new storage of proper size
        strcpy(linePtr, thatLine.linePtr);   // copy
                                    //strcpy(this->linePtr, m.linePtr); // same as above
    }
    return *this;
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

bool empty(){

	
	if ( (this*) != NULL && this[0] == '\0' ) {
    
		return true;// empty
	}
	
	else return false;
	

	return true;
}

bool full(){

	return false;

}

const int capacity(){

	 cout << "capacity" << endl;

	 return 1;

}

void resize (){

	 cout << "resize" << endl;

}

void push_back (const char& someChar){

	 cout << "push back" << endl;

}

void pop_back (){

	cout << "pop back" << endl;

}


*/