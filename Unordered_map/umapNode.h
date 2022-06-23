#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<class T1 , class T2>
class Node
{

public:
	T1 key;
	T2 value;
	Node* next;

 

	Node()
	{
		key = 0;
		value = 0;
		next = NULL;
	}

	Node(T1 tkey , T2 tval)
	{
		key = tkey;
		value = tval;
		next = NULL;
	}

	Node(Node* temp)
	{
		key = temp->key;
		value = temp->value;
		next = temp->next;
	}


	T1 getKey()
	{
		return key;
	}

	T2 getValue()
	{
		return value;
	}

	Node* getNext()
	{
		return next;
	}

	void setNext(Node* temp)
	{
		next = temp;
	}

	void setNextNull()
	{
		next = NULL;
	}

};
