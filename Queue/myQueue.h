#include<iostream>
#include"myList.h"

using namespace std;

template<class T>
class Queue
{
	List<T> *queueList = new List();
	int size_=0;

 public:

	Queue(){};
	~Queue(){};
	T& front();
	void pop();
	void push(T);
	int size();
	bool empty();
};

void Queue<T>::push(T elem)
{
        queueList->push_back(elem);
        size_++;
}

template<class T>
void Queue<T>::pop()
{
        if(!size_)return;

        queueList->pop_front();
        size_--;
}

template<template<class T>
T& Queue<T>::front()
{
        if(size_)return queueList->front();

}

template<class T>
int Queue<T>::size()
{
        return size_;
}

template<class T>
bool Queue<T>::empty()
{
        return size_==0;
}
