#include "LinkedList.h"

using namespace std;


int main(){
	{


	LinkedList<string> l;
	
	l.push_back("Gleb Revolutionary");

	l.push_back("Anna Arabienko");

	l.push_back("Dima Immigrainienko");

	l.push_back("Andrea Poyehavshaya");

	l.push_back("Alissa My Baby");

	
	l.print();

	LinkedList<string> someList(l);

	
	someList.print();


	LinkedList<string> beb;

	beb=l;

	beb.print();


	
	
	
	
	//someList.push_back("Test");



	//LinkedList<string> oneList;

	//oneList=someList;


	



	}

	
	

	/*
	

	LinkedList<string> anotherList;

	anotherList=l;

	anotherList.print();

	anotherList.pop_back();

	anotherList.print();

	anotherList.push_back("Indian Goswami");

	anotherList.print();


	LinkedList<string> indianList = anotherList;

	indianList.print();

	indianList.pop_back();

	indianList.print();
	*/

	//indianList.push_back("Sacred Cow");

	//indianList.print();



	





	while(true){
	
	}


}