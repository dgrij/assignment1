#include <iostream>     // for cout and cin
//#include "LineKeeper.h"   // for LineKeeper class
#include "Line.h"
#include"string.h"
using namespace std;   // safe to use this using-directive here

int main()
{
   
	{
	
	Line line ("Dmitri");
	line.print();

	Line dmitriCopy(line);
	dmitriCopy.print();
		
	Line empty;
	empty.print();
	
	cout<<line<<endl;

	
	//empty.print();
	
	Line anotherLine;

	anotherLine = dmitriCopy;

	cout<<anotherLine<<endl;



	}
	
	
	while (true){	}
	
	
	
	
	/*



	FILE * pFile;
char mystring[100];

fope_s(&pFile, "a.txt", "r");
if (pFile == NULL) perrror ("error opening file");
else {
 while (fgets (mystring,100,pFile) != NULL)
cout<<mystring;
fclose(pFile);
}





int*c = new int(9);
int d=9;



cout << *c<<end;
c =&d;
cout <<*c<<endl;

int a[10]




















	*/
	
	
	














	
	
	
	
	
	
	











	
	/*
	
	LineKeeper m1; // an empty string
    cout << "m1:" << m1 << endl;

    LineKeeper m2("too many friends spoil information hiding!");
    cout << "m2:" << m2 << endl;

    {
        LineKeeper m2("I'm different from the m2 object above, " // note how we split
            "and just about to die, bye!"); // C-strings across lines
        cout << "m:" << m2 << endl;
    }

    LineKeeper m3{ m2 }; // copy ctor, C++11
    cout << "m3:" << m3 << endl;

    LineKeeper m4(m3);   // copy ctor
    cout << "m4:" << m4 << endl;

    LineKeeper m5 = m4;  // copy ctor
    cout << "m5:" << m5 << endl;

    m1 = m3;         // copy assignment overload
    cout << "m1:" << m1 << endl;

    pm->print();
    //  (*pm).print();   // same as above
    delete pm;
    pm = nullptr;  // defensive programming

	*/

    //return 0;   // same as return EXIT_SUCCESS; from <cstdlib>

	
}
