#include<iostream>
#include"VectorImplementation.h"
using namespace std;

template<class T>
class Priority_queue
{
	Vector<T> pqArray;
	int size_ = 0;
 public:

	Priority_queue(){};
	Priority_queue(T* , T*);
	int size();
	void push(T);
	T top();
	T pop();
	void swap(T& , T&);
};


template<class T>
int Priority_queue<T>::size()
{
	return size_;
}

template<class T>
Priority_queue<T>::Priority_queue(T* start , T* end)
{
	while(start != end)push(*start);
}

template<class T>
void Priority_queue<T>::push(T temp)
{
	pqArray.push_back(temp);
	size_ = pqArray.size();

	int i = pqArray.size()-1;
	int par = (i>>1);
	while(i>0)
	{
		par = i>>1;
		if(pqArray[par]<pqArray[i])
		{
			swap(pqArray[par],pqArray[i]);
			i = par;
		}
		else break;
	}
}


template<class T>
void Priority_queue<T>::swap(T& a , T& b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}

template<class T>
T Priority_queue<T>::top()
{
	if(pqArray.size())
	return pqArray[0];

	return '\0';
}

template<class T>
T Priority_queue<T>::pop()
{
	if(pqArray.size()==0)return '\0';

	T temp = pqArray[0];
	pqArray[0] = pqArray[size_-1];
	pqArray.pop_back();
	size_--;

	int par = 0;
	int l,r;

	while(par<size_)
	{
		l = par*2+1;
		r = par*2+2;

		if(r<size_)
		{
			if(pqArray[l]>pqArray[r])
			{
				swap(pqArray[l],pqArray[par]);
				par = l;
			}
			else
			{
				swap(pqArray[r],pqArray[par]);
				par = r;
			}
		}
		else if(l<size_)
		{
			swap(pqArray[l],pqArray[par]);
                        par = l;

		}
		else break;
	}

	return temp;
}
