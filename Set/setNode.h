#include <iostream>

using namespace std;

template<class T>
class Node
{
	T data;
	Node<T> *left , *right;

   public:

	Node();
	Node(T );
	~Node(){};

	void setdata(T);
	void setleft(Node<T>*);
	void setright(Node<T>*);
	void setleftnull();
	void setrightnull();
	void setbothnull();
	Node<T>* getleft();
	Node<T>* getright();
	T getdata();

};

template<class T>
Node<T>::Node()
{
	data = 0;
	left = NULL;
	right = NULL;
}

template<class T>
Node<T>::Node(T val)
{
	data = val;
	left = NULL;
	right = NULL;
}

template<class T>
void Node<T>::setdata(T val)
{
	data = val;
}

template<class T>
void Node<T>::setleft(Node<T> *temp)
{
	left = temp;
}
template<class T>
void Node<T>::setright(Node<T> *temp)
{
	right = temp;
}


template<class T>
void Node<T>::setrightnull()
{
	right = NULL;
}

template<class T>
void Node<T>::setleftnull()
{
	left = NULL;
}

template<class T>
void Node<T>::setbothnull()
{
	left = NULL;
	right = NULL;
}

template<class T>
T Node<T>::getdata()
{
	return data;
}

template<class T>
Node<T>* Node<T>::getleft()
{
	return left;
}

template<class T>
Node<T>* Node<T>::getright()
{
        return right;
}

