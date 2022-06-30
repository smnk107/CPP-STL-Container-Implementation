#include<iostream>
#include"myList.h"

using namespace std;

template<class T>
class Stack
{
	List<T> *stackList = new List();
	int size_=0;

 public:

	Stack(){};
	~Stack(){};
	T& top();
	void pop();
	void push(T);
	int size();
	bool empty();
};

template<class T>
void Stack<T>::push(T elem)
{
	stackList->push_back(elem);
	size_++;
}

template<class T>
void Stack<T>::pop()
{
	if(!size_)return;

	stackList->pop_back();
	size_--;
}

template<template<class T>
T& Stack<T>::top()
{
	if(size_)return stackList->back();

}

template<class T>
int Stack<T>::size()
{
	return size_;
}

template<class T>
bool Stack<T>::empty()
{
	return size_==0;
}
