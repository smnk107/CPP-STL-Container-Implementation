#include<iostream>
#include"listNode.h"

using namespace std;

template<class T>
class list_iterator
{
	Node<T> *itr;

  public:

	list_iterator();
	list_iterator(Node<T>*);
	~list_iterator();

	list_iterator<T> operator++(int);
	list_iterator<T> operator++();
	list_iterator<T> operator--(int);
	list_iterator<T> operator--();
	T operator*();

	Node<T>* getnode();
	bool isNull();

	bool operator!=(const list_iterator&);
	bool operator==(const list_iterator&);
};

template<class T>
bool list_iterator<T>::isNull()
{
	return itr==NULL;
}

template<class T>
list_iterator<T>::list_iterator()
{
	itr=NULL;
}

template<class T>
list_iterator<T>::list_iterator(Node<T>* temp)
{
	itr = temp;
}
template<class T>
list_iterator<T>::~list_iterator()
{
//	if(itr)delete itr;
}

template<class T>
list_iterator<T> list_iterator<T>::operator++(int)
{
	Node<T>* temp;
	temp=itr;
	itr = itr->getnext();

	list_iterator tr(temp);
	return tr;
}

template<class T>
list_iterator<T> list_iterator<T>::operator++()
{
	itr = itr->getnext();
	return *this;
}

template<class T>
list_iterator<T> list_iterator<T>::operator--(int)
{
	list_iterator<T> temp = itr;
	itr = itr->getprev();

	return temp;
}

template<class T>
list_iterator<T> list_iterator<T>::operator--()
{
	itr = itr->getprev();
	return  *this;
}

template<class T>
bool list_iterator<T>::operator!=(const list_iterator<T> &temp)
{
	return (itr != temp.itr);
}

template<class T>
bool list_iterator<T>::operator==(const list_iterator<T> &temp)
{
	return (itr == temp.itr);

}
template<class T>
T list_iterator<T>::operator*()
{
	return itr->getdata(); 
}

template<class T>
Node<T>* list_iterator<T>:: getnode()
{
	return itr;
}


