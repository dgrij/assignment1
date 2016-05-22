#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
using std::cout;
using std::endl;
using std::strcpy;


template<typename T>
class Node{ 

	template <typename T>
	friend class LinkedList;


private:

	T data;
	Node<T> *next;
	Node<T> *prev;
	
public:


	Node(){
	next = nullptr;
	prev = nullptr;
		
	}

	
	Node(T someData){
	next = nullptr;
	prev = nullptr;
	data = someData;
	
	}

	
	void print(){
		cout<<"["<<data<<"]"<<endl;
	}
	
	void setData(T x){
	data = x;
	}

	void linkNode(Node &that){
	
		next = &that;

	}


	void printNext(){
	
	cout<<next->data<<endl;
	
	}






};


class Message{
	
	template <typename T>
	friend class LinkedList;

	// Using-declarations

private:

    char* msgPtr;     

public:



Message() 
{
    msgPtr  = new char[1];
    msgPtr[0] = '\0';
    cout << "default Message ctor" << endl;

}



/*

Message() : msgPtr{ new char[1]{ '\0' } }
{
    //msgPtr  = new char[1];
    //msgPtr[0] = '\0';
    cout << "default Message ctor" << endl;

}

*/

Message(char *cstr)
{
    cout << "ctor Message(char *)" << endl;
    msgPtr = new char[strlen(cstr) + 1]; // what's the +1 for?
    strcpy(msgPtr, cstr);

}

Message(const Message& m)
{
    cout << "Message copy ctor" << endl;
    msgPtr = new char[strlen(m.msgPtr) + 1];
    strcpy(msgPtr, m.msgPtr);
}


~Message()
{
    cout << "Message dtor" << endl;
    delete[] msgPtr;
    msgPtr = nullptr;   // defensive programming
}
const Message& operator =(const Message &m)
{
    cout << "assignment operator overload (copy assignment)" << endl;
    if (this == &m) return *this; // do nothing on self-assignment
    {
        delete[] msgPtr; // release dynamic storage currently used by the LHS operator
        msgPtr = new char[strlen(m.msgPtr) + 1]; // allocate new storage of proper size
        strcpy(msgPtr, m.msgPtr);   // copy
                                    //strcpy(this->msgPtr, m.msgPtr); // same as above
    }
    return *this;
}

// just a friend member, privileged to see the private members of its parameter m
// note: the keyword 'friend' has no meaning, and should not be used, outside a class
ostream& operator<<(ostream& out, const Message& m)
{
    out << m.msgPtr;
    return out;
}

// we did not write this member function in class
void print() const // const means that print cannot modify *this
{
    cout << msgPtr << endl; // showing off using our own operator<< overload
    cout << this->msgPtr << endl; // same as above
    cout << (*this).msgPtr << endl; // same as above
}




};













template<typename T>
class LinkedList{

private:


Node<T>* head;
Node<T>* tail;
size_t size;

public:

//constructors


LinkedList () {

	head = nullptr;
	tail = nullptr;
	size = 0;

}


LinkedList (const LinkedList<T>& thatList){

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

~LinkedList (){

}


//method declaration

		void push_front(T data){

	
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

		
		void push_back(T data){
	
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

					cout<<"Last node deleted, your list is empty"<<endl;

					size--;

					return;
				}

				Node<T>* temp = head->next;
		
	
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


			

				void print(){

				Node<T>* temp;

				temp = head;

				cout<<"[LIST HEAD]-"<<"[LIST SIZE: "<<size<<"]"<<endl;

				while (temp!=nullptr){

					temp->print();
					temp=temp->next;
				}

				cout<<"[LIST TAIL]"<<endl;
				
				}
				
				};





int main(){



//cout<< addTwoTypes<int>(4,3)<<endl;


//cout<< addTwoTypes<float>(2.4,3.5)<<endl;


/*

Node<int> firstNode;
firstNode.setData(4);
firstNode.print();




Node<int> otherNode;
otherNode.setData(9999);
otherNode.print();

firstNode.linkNode(otherNode);

firstNode.printNext();

*/



LinkedList<string> MyList;




MyList.push_front("Dima Grijalva");
MyList.push_front("Gleb Komissarov");
MyList.push_front("Donald Trump");
MyList.push_front("Anna Ukrainenko");
MyList.push_front("Andrea Gandarezca");
MyList.push_front("Alissa Isabelezca");
MyList.push_back("Professor X");
MyList.push_back("Professor X");
MyList.push_back("Professor X");
MyList.push_front("Professor X");
MyList.print();
MyList.pop_back();
MyList.pop_front();

MyList.print();


//LinkedList<string> Copied = LinkedList<string>(MyList);

//Copied.print();













while(true){}






}




