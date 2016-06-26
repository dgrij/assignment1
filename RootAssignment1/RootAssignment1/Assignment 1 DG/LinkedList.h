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


template<typename D>
class LinkedList{
	
	private: 

				
				class ListNode{ 
		
				friend class LinkedList;

				D data;
				ListNode* next;
				ListNode* prev;
	
				//NODE OBJECT DEFINITION

				
								
				ListNode (): data(){

				next = nullptr;
				prev = nullptr;
			

				}
				
				ListNode(const D& someData):data(someData){

					next = nullptr;
					prev = nullptr;
						
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

	ListNode* temp;

	size_t size;          

	

public:	void copy(const LinkedList& thatList){
	
		head = new ListNode();
		tail = new ListNode();
		size=0;
		head->next=tail;
		tail->prev=head;

		// temp=thatList.head;

		ListNode* current=thatList.head;


		current=current->next;

		while (current!=thatList.tail){
		
		//temp->print();
		// cout << "here"<<endl;

		push_back(current->data);

		current= current->next;

		
		}

		



	
	}
	
	


	void del() {
	

		while (head!=nullptr){
		
		
		temp=head;

		head=head->next;

		delete temp;

		}

		size=0;
		tail=nullptr;

		// cout<<"deleted"<<endl;

	}

	

	
public:


	LinkedList& operator=(const LinkedList& thatList){
	if(this!=&thatList){
	del();
	copy(thatList);
	}
	return *this;


	}
 
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



LinkedList () : head(new ListNode()), tail(new ListNode()), size(0) {

	tail->prev = head;
	head->next = tail;
	
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

	if (this != &thatList)
		copy(thatList);

}





~LinkedList(){

	del();
}


//method declaration
void push_front(const D& data){

					
		temp = new ListNode (data);
	
		head->next->prev = temp;
		
		temp->next=head->next;

		head->next=temp;

		temp->prev=head;	
		
		size++;



		}

void push_back(const D& data){
	
			
		temp = new ListNode (data);
	
		tail->prev->next = temp;
		
		temp->prev=tail->prev;

		tail->prev= temp;

		temp->next=tail;	
		
		size++;


		}


				
void pop_front(){
	
				if (size!=0){
	

				temp = head->next;
				
				temp->next->prev=head;
				
				head->next = temp->next;

				delete temp;

				temp = nullptr;

				size--;

				}
	
	

	


}

void pop_back(){

				
				if (size!=0){
	

				temp = tail->prev;
				
				temp->prev->next=tail;
				
				tail->prev = temp->prev;

				delete temp;

				temp = nullptr;

				size--;

				}
}

void print(){

				temp = head->next;

				cout<<"[LIST HEAD]-"<<"[LIST SIZE: "<<size<<"]"<<endl;

				while (temp!=tail){

					temp->print();
					temp=temp->next;
				}

				cout<<"[LIST TAIL]"<<endl;
				
				}


void print(int maxLine){

	if (maxLine < 0) {

		cout<<"[------------NEGATIVE LINE, RESET TO 0 ---------------]"<<endl;
	
		maxLine = 0;
	}

	else if (maxLine > size){


		cout<<"[------------LINE LARGER THAN LIST SIZE, RESET TO SIZE ---------------]"<<endl;

		maxLine = size;
	
	}




				ListNode* temp;

				temp = head->next;

				cout<<"[LIST HEAD]-"<<"[LIST SIZE: "<<size<<"]"<<endl;

				
				for (int i = 0; i < maxLine; i++) {
				
					cout<<"("<<i+1<<") ";

					temp->print();

					temp=temp->next;

				}
								
								
				cout<<"[LIST TAIL]"<<endl;
				
				}



void print(int minLine, int maxLine ){

	if (maxLine<minLine){
	
		cout<<"[------------INVALID RANGE OF LINES, LINES WILL BE INVERTED---------------]"<<endl;

		int tempMax = minLine;
			
		minLine = maxLine;

		maxLine = tempMax;
		
	}
	
	if (minLine < 0) {
	
		cout<<"[------------NEGATIVE MIN LINE, RESET TO 0 ---------------]"<<endl;

		minLine = 0;
	}

	else if (minLine > size){

		cout<<"[------------MIN LINE LARGER THAN LIST SIZE, RESET TO SIZE ---------------]"<<endl;

		minLine = size;
	
	}

	

	if (maxLine < 0) {

		cout<<"[------------NEGATIVE MAX LINE, RESET TO 0 ---------------]"<<endl;
	
		maxLine = 0;
	}

	else if (maxLine > size){


		cout<<"[------------MAX LINE LARGER THAN LIST SIZE, RESET TO SIZE ---------------]"<<endl;

		maxLine = size;
	
	}

	




	ListNode* temp;

				temp = head->next;

				cout<<"[LIST HEAD]-"<<"[LIST SIZE: "<<size<<"]"<<endl;

				
				for (int i = 0; i < maxLine; i++) {
				
					if (i >= minLine-1){					
					
					cout<<"("<<i+1<<") ";

					temp->print();
										
					}
					
					temp=temp->next;

				}
								
								
				cout<<"[LIST TAIL]"<<endl;
				
				}









};











#endif

