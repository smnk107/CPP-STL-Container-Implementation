#include<iostream>
//#include"listNode.h"
#include"listIterator.h"
#include<vector>
#include<algorithm>
template<class T>
class List
{

	Node<T> *head;
	Node<T> *tail;
	int size;
 public:
	List();
	List(List<T>&);

	void push_back(T);
	void pop_back();
	void push_front(T);
	void pop_front();
	T& front();
	T& back();
	list_iterator<T> begin();
	list_iterator<T> end();
	void assign(int,T);
	void assign(list_iterator<T> , list_iterator<T> );
	void insert(list_iterator<T>,T);
	void erase(list_iterator<T>);
	void remove(T);
	void display();
	bool empty();
	void delAll();
	void clear();
	void Sort();
	void reverse();
	void clear();
	int length();
};


template<class T>
List<T>::List()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

template<class T>
List<T>::List(List<T>& temp)
{
	head = temp.head;
	tail = temp.tail;
	size = temp.size;
}

template<class T>
void List<T>::push_back(T val)
{
	Node<T> *node=new Node<T>(val);

	if(head==NULL)
	{
		head = node;
		tail = node;
		size = 1;
	}
	else
	{
		tail->setnext(node);
		node->setprev(tail);
		tail = node;
		//tail->setnext(NULL);
		size++;
	}

}

template<class T>
void List<T>::display()
{
	list_iterator<T> itr=this->begin();

	while(itr!=NULL)
	{
		cout<<*itr<<" ";
		itr++;
	}
}

template<class T>
int List<T>::length()
{
	return size;
}


template<class T>
void List<T>::pop_back()
{
	Node<T> *temp = tail->getprev();
	size--;
	temp->setnext(NULL);
	delete tail;
	tail = temp;
}

template<class T>
void List<T>::push_front(T val)
{
	Node<T> *temp = new Node<T>(val);
	if(head==NULL)
	{
		head = temp;
		tail = temp;
		size++;
	}
	else
	{
		temp->setnext(head);
		head->setprev(temp);
		head = temp;
		size++;
	}

}

template<class T>
void List<T>::pop_front()
{
	Node<T> *temp = head->getnext();
//	delete head;
	head = temp;
	head->setprev(NULL);
	size--;
}


template<class T>
T& List<T>::front()
{
	return head->getdata();
}


template<class T>
T& List<T>::back()
{
	return tail->getdata();
}


template<class T>
list_iterator<T> List<T>::begin()
{
	list_iterator<T> temp(head);
	return temp;
}

template<class T>
list_iterator<T> List<T>::end()
{
	list_iterator<T> temp(tail);
	return temp;
}

template<class T>
void List<T>::insert(list_iterator<T> pos , T val)
{
	if(pos==begin())
	{
		push_front(val);
		size++;
	}
	else
	{
		Node<T> *temp = new Node<T>(val);
		Node<T> currNode = pos.getnode();
		Node<T> currPrevNode = currNode->getprev();
		temp->setnext(currNode);
		temp->setprev(currPrevNode);
		currPrevNode.setnext(temp);
		size++;
	}

}


template<class T>
void List<T>::assign(list_iterator<T> beg , list_iterator<T> end)
{
	head = beg.getnode();
	tail = end.getnode();
}

template<class T>
void List<T>::assign(int n , T val)
{
	for(int i=0 ; i<n ; i++)
	push_back(val);
}

template<class T>
void List<T>::erase(list_iterator<T> temp)
{

	if(temp==begin())
	{
		pop_front();
		size--;
	}
	else
	{
		Node<T>* currNode =  temp.getnode();
		Node<T>* currNodePrev = currNode->getprev();
		Node<T>* currNodeNext = currNode->getnext();
		currNodePrev->setnext(currNodeNext);
		currNodeNext->setprev(currNodePrev);
		size--;
		//delete currNode;
	}
}

template<class T>
void List<T>::remove(T val)
{
	list_iterator<T> start = begin();

	while(start != NULL)
	{
		if((*start)==val)erase(start);
			start++;
	}
}

template<class T>
void List<T>::delAll()
{
	while(head != NULL)
	{
		Node<T> *t = head->getnext();
		delete head;
		head = t;
	}
	tail = NULL;
	head = NULL;
	size = 0;
}

template<class T>
void List<T>::Sort()
{
	vector<T> v;
	Node<T> *start = head , *temp;

	while(start!=NULL)
	{
		v.push_back(start->getdata());
		start= start->getnext();
	}

	delAll();
	sort(v.begin(),v.end());

	for(int i=0 ; i<v.size() ; i++)
	push_back(v[i]);

}

template<class T>
void List<T>::reverse()
{
	Node<T> *start = head , *temp = NULL;

	while(start!=NULL)
	{
		temp = start->getnext();
		start->setnext(start->getprev());
		start->setprev(temp);
		start = temp;
	}

	temp = head;
	head = tail;
	tail = head;
}

template<class T>
void List<T>::clear()
{
	delAll();
}
