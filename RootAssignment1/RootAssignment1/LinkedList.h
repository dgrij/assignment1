#pragma once          // same as  include guards below, but non-standard
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>     // for ostream

using std::ostream;

template<typename T> class LinkedList
{
	
	template<typename T> 


private:
	
	
    Node<T>* head;
		
	Node<T>* tail;

	size_t size;                   

public:
 
// Linked List Constructors

	LinkedList ();                                  // default constructor
   
	LinkedList(Node<T>*);		// a constructor overload
    
	LinkedList (const LinkedList<T>& thatList);		// copy constructor
   
	~LinkedList ();									// destructor
    
	template<typename T> const LinkedList& operator=(const LinkedList&);	// assignment operator overload
    
	template<typename T> friend ostream& operator<<(ostream& output, const LinkedList& thatList);  // we did not write this member function in class
    	
// Linked List Methods

	void print() const;		// const means that print does not modify *this
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();

};

#endif

