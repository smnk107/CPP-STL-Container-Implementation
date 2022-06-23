#include<iostream>
#include<algorithm>
#include"setNode.h"

using namespace std;

template<class T>
class Set
{
	Node<T>* root;
	Node<T>* curr;
	Node<T>* prev;
	//T* begin;
	//T* end;
	T* setArr;
	long long size_=0;

  public:

	Set();
	Set(T*,T*);
	void insert(T);
	bool search(T);
	void renew(T);
	void display(Node<T>*);
	void display();
	void erase(T);
	void erase(Node<T>*);
	void Erase(T);
	T* find();
	T findRightMin(Node<T>*);
	void renewErase(T);
	T* begin(){return setArr;}
	T* end(){return setArr+size_;}
	int size(){return size_;}
	void clear();


};

template<class T>
Set<T>::Set()
{
	root = NULL;
	curr = NULL;
	prev = NULL;
	setArr = NULL;
}

template<class T>
Set<T>::Set(T* strt , T *nd )
{
	Set();
	while(strt != nd)
	{
		insert(*strt);
		strt++;
	}
}

template<class T>
void Set<T>::insert(T elem)
{
	Node<T> *node = new Node<T>(elem);

	if(root==NULL)
	{
		root = node;
	}
	else if(!search(elem))
	{
		T prevData = prev->getdata();
		if(prevData > elem)prev->setleft(node);
		else prev->setright(node);
	}

	renew(elem);
}

template<class T>
bool Set<T>::search(T elem)
{
	if(root==NULL) return false;

	curr = root;
	prev = curr;

	while(curr != NULL)
	{
		//prev = curr;
		T currData = curr->getdata(); 
		if(currData > elem)
			prev = curr,curr = curr->getleft();
		else if(currData < elem)
			prev = curr,curr = curr->getright();
		else return true;
	}

	return false;
}

template<class T>
void Set<T>::renew(T elem)
{
	T *newArr =new T[++size_];
	newArr[size_-1]=elem;
	if(setArr==NULL)
	{
		setArr = newArr;
		return;
	}

	for(int i=0 ; i<size_-1 ; i++)
		newArr[i]=setArr[i];

	sort(newArr,newArr+size_);

	if(setArr!=NULL)delete setArr;
	setArr =  newArr;
}

template<class T>
void Set<T>::display(Node<T> *temp)
{

	if(temp->getleft()!=NULL)display(temp->getleft());
	cout<<temp->getdata()<<",";
	if(temp->getright()!=NULL)display(temp->getright());
}

template<class T>
void Set<T>::display()
{
	display(root);
}


template<class T>
void Set<T>::renewErase(T elem)
{
        T *newArr =new T[--size_];

	int j=0;
        for(int i=0 ; i<=size_ ; i++)
                if(setArr[i]!=elem)newArr[j++]=setArr[i];

        sort(newArr,newArr+size_);

        if(setArr!=NULL)delete setArr;
        setArr =  newArr;
}




template<class T>
void Set<T>::Erase(T val)
{
	//cout<<val<<endl;
	if(search(val))
	{
		cout<<val<<endl;
		int pos = 0;
		if(val == root->getdata())pos = -1;
		else if( val > prev->getdata() )pos = 1;

		//T mini = findRightMin(curr);


		if(curr->getleft()==NULL && curr->getright()==NULL)
		{
			if(pos==-1)root = NULL;
			else if(pos==1)prev->setrightnull();
			else prev->setleftnull();
		}
		else if(curr->getleft()==NULL)
		{
			Node<T>* t = curr->getright();
			if(pos==-1)root = t;
			else if(pos==1 )
			{
				prev->setright(t);
			}
			else prev->setleft(t);
		}
		else if(curr->getright()==NULL)
		{
			Node<T>* t = curr->getleft();
			if(pos==-1)root = t;
			else if(pos==1) prev->setright(t);
			else prev->setleft(t);
		}
		else
		{
			T tempv = findRightMin(curr->getright());
	//		cout<<tempv<<endl;
			Node<T> *store = curr;
			Erase(tempv);
			store->setdata(tempv);
		}
	}
}


template<class T>
void Set<T>::erase(T temp)
{
	Erase(temp);
	renewErase(temp);
}

template<class T>
void Set<T>::erase(Node<T> *temp)
{
	T tempv = temp->getdata();
	Erase(tempv);
	renewErase(tempv);
}
template<class T>
T Set<T>::findRightMin(Node<T> *temp)
{
	while(temp->getleft()!=NULL)temp = temp->getleft();
	return temp->getdata();
}

template<class T>
void Set<T>::clear()
{
	root = NULL;
	delete[] setArr;
}


template<class T>
T* Set<T>::find(T val)
{
	int low = 0;
	int high = size_-1;
	int mid ;

	while(low<=high)
	{
		mid = (low+high)/2;
		if(setArr[mid]==val)return setArr_+mid;
		else
		{
			if(setArr[mid]>val)high = mid-1;
			else low = mid+1;
		}
	}

	return end();
}
