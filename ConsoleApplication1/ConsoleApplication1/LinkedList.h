#pragma once          // same as  include guards below, but non-standard
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>     // for ostream
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;
using std::ostream;
using std::cout;
using std::endl;
using std::strcpy;



class LinkedList{
	
	private: 
		
				class ListNode{ 
		
				friend class LinkedList;

				int data;
				ListNode* next;
				ListNode* prev;
	
				//NODE OBJECT DEFINITION

				ListNode (){

				next = nullptr;
				prev = nullptr;
				data = 0;

				}
				
				ListNode(int& someData){

					next = nullptr;
					prev = nullptr;
					data = someData;
	
				}

				~ListNode(){
				}

				void print(){
				
					cout<<data<<endl;

				}

				/*

				ListNode (const T& someLine, ListNode* prevNode, ListNode* nextNode){

					T& = someLine;
					ListNode* = prevNode;
					ListNode* = nextNode;

				}

				ListNode (T& someLine){

					T& = someLine;
					next = nullptr;
					prev = nullptr;
	
				}

				*/

				

			};

	

	ListNode* head;
		
	ListNode* tail;

	size_t size;                   

public:
 
// Linked List Constructors

                                 // default constructor
   
	//LinkedList(ListNode<T>*);		// a constructor overload
    
	//LinkedList (const LinkedList<T>& thatList);		// copy constructor
   
	//~LinkedList ();									// destructor
    
	//const LinkedList& operator=(const LinkedList&);	// assignment operator overload
    
	//friend ostream& operator<<(ostream& output, const LinkedList& thatList);  // we did not write this member function in class
    	
// Linked List Methods

	//void print() const;		// const means that print does not modify *this
	//void push_front(T data);
	//void push_back(T data);
	//void pop_front();
	//void pop_back();



/*
//
//	TEMPLATE DEFINITIONS
//
*/



LinkedList () {

	head = nullptr;
	tail = nullptr;
	size = 0;

}
/*
LinkedList (const LinkedList& thatList){

	head = nullptr;
	tail = nullptr;
	size = thatList.size;
		
	ListNode* current = head = new ListNode(thatList.head->data);

	while (current != nullptr)
	{
		
		push_back (current->data);

		current=current->next;

	}

}*/


LinkedList (const LinkedList& thatList){

	head = nullptr;
	tail = nullptr;
	size = thatList.size;
		
	ListNode* temp = head = new ListNode(thatList.head->data);

	ListNode* temp2 = thatList.head->next;
	
	while (temp2 != nullptr)
	{
		temp->next = new ListNode(temp2->data);
		
		temp = temp->next;
		
		temp2 = temp2->next;

	}

}



~LinkedList(){
}


//method declaration
void push_front(int data){

	
		if (size == 0){

				
		ListNode* temp = new ListNode (data);
	
		head = temp;
		
		tail = temp;
		
		size++;

		return;
	
		}

		
		ListNode* temp = new ListNode (data);
	
		temp->next = head;
		
		head->prev = temp;
				
		head=temp;

		size++;

		}

void push_back(int data){
	
		if (size == 0){
				
		ListNode* temp = new ListNode (data);
	
		head = temp;
		tail = temp;
	
		size++;

		return;
	
		}

	
		ListNode* temp = new ListNode (data);
	
		temp->prev = tail;
		
		tail->next = temp;
		
		tail=temp;

		size++;


		}


				
void pop_front(){
	
				if (size == 0){

				
				cout<<"Your LinkList is empty... nothing to pop"<<endl;

				return;
	
				}


				else if (head == tail)
				{
					delete head;
					head = nullptr;
					tail = nullptr;

					cout<<"Last ListNode deleted, your list is empty"<<endl;

					size--;

					return;
				}

				ListNode* temp = head->next;
		
	
				delete head;
	
				head=temp;

				size--;

	


}

void pop_back(){

				if (size == 0){

				
				cout<<"Your LinkList is empty... nothing to pop"<<endl;

				return;
	
				}


				else if (head == tail)
				{
					delete head;
					head = nullptr;
					tail = nullptr;

					cout<<"Last ListNode deleted, your list is empty"<<endl;

					size--;

					return;
				}

				ListNode* temp = tail->prev;
		
	
				delete tail;
	
				tail=temp;

				tail->next = nullptr;

				size--;
				
				}


void print(){

				ListNode* temp;

				temp = head;

				cout<<"[LIST HEAD]-"<<"[LIST SIZE: "<<size<<"]"<<endl;

				while (temp!=nullptr){

					temp->print();
					temp=temp->next;
				}

				cout<<"[LIST TAIL]"<<endl;
				
				}




};











#endif

