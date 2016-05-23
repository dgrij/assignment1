//#pragma once          // same as  include guards below, but non-standard
#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream> // for ostream
#include "Line.h"
using std::ostream;

class ListNode{ 
	
private:

	Line& data;
	ListNode* next;
	ListNode* prev;
	
	
public:
	
ListNode();
		
ListNode(T someData){

	next = nullptr;
	prev = nullptr;
	data = someData;
	
}

string getCurrData();

string getNextData();

string getPrevData();

void setCurrData(Line& data);

void setPrevData(Line& data);

void setNextData(Line& data);

}; #endif

