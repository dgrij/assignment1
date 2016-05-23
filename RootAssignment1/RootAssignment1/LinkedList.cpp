#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include "LinkedList.h"

using namespace std;
using std::cout;
using std::endl;
using std::strcpy;


template<typename T> LinkedList<T>::LinkedList () {

	Node::head = nullptr;
	Node::tail = nullptr;
	size = 0;

}

template<typename T> LinkedList<T>::LinkedList (const LinkedList<T>& thatList){

	head = nullptr;
	tail = nullptr;
	size = thatList.size;
		
	Node<T>* current = head = new Node<T>(thatList.head->data);

	while (current != nullptr)
	{
		
		push_back (current->data);

		current=current->next;

	}

}

/*
LinkedList (const LinkedList<T>& thatList){

	head = nullptr;
	tail = nullptr;
	size = thatList.size;
		
	Node<T>* temp = head = new Node<T>(thatList.head->data);

	Node<T>* temp2 = thatList.head->next;
	
	while (temp2 != nullptr)
	{
		temp->next = new Node<T>(temp2->data);
		
		temp = temp->next;
		
		temp2 = temp2->next;

	}

}

*/
template<typename T> LinkedList<T>::~LinkedList(){
}


//method declaration
template<typename T> void LinkedList<T>::push_front(T data){

	
		if (size == 0){

				
		Node<T>* temp = new Node<T> (data);
	
		head = temp;
		
		tail = temp;
		
		size++;

		return;
	
		}

		
		Node<T>* temp = new Node<T> (data);
	
		temp->next = head;
		
		head->prev = temp;
				
		head=temp;

		size++;

		}

	template<typename T> void LinkedList<T>::push_back(T data){
	
		if (size == 0){
				
		Node<T>* temp = new Node<T> (data);
	
		head = temp;
		tail = temp;
	
		size++;

		return;
	
		}

	
		Node<T>* temp = new Node<T> (data);
	
		temp->prev = tail;
		
		tail->next = temp;
		
		tail=temp;

		size++;


		}


				
template<typename T> void LinkedList<T>::pop_front(){
	
				if (size == 0){

				
				cout<<"Your LinkList is empty... nothing to pop"<<endl;

				return;
	
				}


				else if (head == tail)
				{
					delete head;
					head = nullptr;
					tail = nullptr;

					cout<<"Last node deleted, your list is empty"<<endl;

					size--;

					return;
				}

				Node<T>* temp = head->next;
		
	
				delete head;
	
				head=temp;

				size--;

	


}

template<typename T> void LinkedList<T>::pop_back(){

				if (size == 0){

				
				cout<<"Your LinkList is empty... nothing to pop"<<endl;

				return;
	
				}


				else if (head == tail)
				{
					delete head;
					head = nullptr;
					tail = nullptr;

					cout<<"Last node deleted, your list is empty"<<endl;

					size--;

					return;
				}

				Node<T>* temp = tail->prev;
		
	
				delete tail;
	
				tail=temp;

				tail->next = nullptr;

				size--;
				
				}


//template void LinkedList<string>();

/*			

template<typename T> void LinkedList<T>::print(){

				Node<T>* temp;

				temp = head;

				cout<<"[LIST HEAD]-"<<"[LIST SIZE: "<<size<<"]"<<endl;

				while (temp!=nullptr){

					temp->print();
					temp=temp->next;
				}

				cout<<"[LIST TAIL]"<<endl;
				
				}
				
*/