#include<iostream>

using namespace std;

template<class T>
class Node
{
	T data;
	Node<T> *next;
	Node<T> *prev;
 public:
	Node();
	Node(T);
	Node(Node<T>&);
	~Node(){};

	void setdata(T);
	void setnext(Node<T>*);
	void setprev(Node<T>*);

	T getdata();
	Node<T>* getnext();
	Node<T>* getprev();
};

template<class T>
Node<T>::Node()
{
	data = 0;
	next = NULL;
	prev = NULL;
}

template<class T>
Node<T>::Node(T val)
{
	data = val;
	next = NULL;
	prev = NULL;
}

template<class T>
Node<T>::Node(Node<T>& temp)
{
	data = temp.data;
	next = temp.next;
	prev = temp.prev;
}

template<class T>
T Node<T>::getdata()
{
	return data;
}

template<class T>
Node<T>* Node<T>::getnext()
{
	return next;
}

template<class T>
Node<T>* Node<T>::getprev()
{
	return prev;
}

template<class T>
void Node<T>::setdata(T val)
{
	data = val;
}

template<class T>
void Node<T>::setprev(Node<T>* addr)
{
	prev = addr;
}

template<class T>
void Node<T>::setnext(Node<T>* addr)
{
	next = addr;
}
