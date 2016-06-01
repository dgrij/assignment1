// Provides definitions for the declarations made in Message.h
#include <iostream>
#include <cstring>
#include "ListNode.h"

// Using-declarations
using std::cout;
using std::endl;
using std::strcpy;

ListNode::ListNode (){

next = nullptr;
prev = nullptr;

}

ListNode::ListNode (const Line& someLine, ListNode* prevNode, ListNode* nextNode){

	Line& = someLine;
	ListNode* = prevNode;
	ListNode* = nextNode;

}

ListNode::ListNode (Line& someLine){

	Line& = someLine;
	next = nullptr;
	prev = nullptr;
	
}


string getCurrData(){

cout<<data<<endl;

}

string getPrevData(){

cout<<prev->data<<endl;

}

string getNextData(){

cout<<next->data<<endl;

}

void setCurrData(T someData){

data = someData;

}


void setNextData(T someData){

next->data = someData;

}

void setPrevData(T someData){

prev->data = someData;

}