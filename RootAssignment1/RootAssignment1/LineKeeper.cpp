// Provides definitions for the declarations made in Line.h
#include "LineKeeper.h"

// Using-declarations
using std::cout;
using std::endl;
using std::strcpy;

LineKeeper::LineKeeper(const char* fileName) //: linePtr{ new char[1]{ '\0' } }
{
    
	cout<<"inside lk"<<endl;

	char* temp = new char[1000];
	std::ifstream fin;
	
	fin.open(fileName);

	/*
	fin.getline(temp, 1000);
	cout << temp<<std::endl;
	fin.getline(temp, 1000);
		cout << temp<<std::endl;
	fin.getline(temp, 1000);
	cout << temp<<std::endl;

	*/


	while(!fin.eof()){
		fin.getline(temp, 1000);
		std::cout << temp<<std::endl;
	}

	fin.close();

	delete[] temp;

}



void print (int m, int n)

{



}

