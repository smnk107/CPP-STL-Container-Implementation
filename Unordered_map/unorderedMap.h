
#include"umapNode.h"
#include<string>
#define MOD_V 9999999


class generator{

public:

static int giveHashValue(char temp)
{
	int t = temp;
	return giveHashValue(t);
}
static int giveHashValue(string str)
{
	int val = 0;
	int n = str.length();
	for(int i=0 ; i<n ; i++)
	{
		val+=((str[i]+i)%MOD_V);
		val%=MOD_V;
	}

	return val;
}

static int giveHashValue(int temp)
{
	int val = 0;
	int t;
	while(temp)
	{
		t = temp%10;
		val+=(t+10);
		val%=MOD_V;
	}

	return val;
}

static int giveHashValue(long temp)
{

	int t = temp;
	t%=MOD_V;
	return giveHashValue(t);
}

static int giveHashValue(float temp)
{
	int t = (temp*10);
	t%=MOD_V;
	return giveHashValue(t);
}


static int giveHashValue(double temp)
{
	int t = (temp*10);
	t%=MOD_V;
	return giveHashValue(t);

}


};
template<class T1 , class T2>
class Unordered_map
{
	Node<T1,T2>** mapArray;
	double loadFactor;
	int size_;
	int capacity;
 public:
	Unordered_map()
	{
		loadFactor = 0.0;
		size_ = 0;
		capacity = 9999999;
		mapArray = new Node<T1,T2>*[capacity];
		for(int i=0 ; i<9999999 ; i++)mapArray[i]=NULL;
	}

	void insert(pair<T1,T2>);
	T2& operator [](T1);
	int size();

};


template<class T1 , class T2>
void Unordered_map<T1,T2>::insert(pair<T1,T2> temp)
{
	T1 tkey = temp.first;
	T2 tval = temp.second;
	
	int flag = 1;

	Node<T1,T2> *node = new Node<T1,T2>(tkey , tval);

	int hashKey = generator::giveHashValue(tkey);
	Node<T1,T2> *t = mapArray[hashKey];
	if(t==NULL) mapArray[hashKey] = node;
	else
	{
		while(t->getNext() != NULL)
		{
			if(t->key==tkey)
			{
				t->value = tval;
				flag = 0;
				break;
			}
			t = t->getNext();
		}
		
		if(t->key==tkey)
		{
			t->value = tval;
			flag = 0;
		}
		else t->setNext(node);
	}

	if(flag)size_++;
}


template<class T1 , class T2>
T2& Unordered_map<T1,T2>:: operator[](T1 temp)
{
	int hashKey = generator::giveHashValue(temp);
	Node<T1,T2> *t = mapArray[hashKey],*prev=t , *node;

	while(t != NULL && t->getKey() != temp)
	{
		prev = t;
		t = t->getNext();
	}

	if(t!=NULL) return t->value;
	else
	{
		node = new Node<T1,T2>(temp,'\0');
		if( mapArray[hashKey]==NULL )mapArray[hashKey] = node;
		else prev->setNext(node);

		size_++;
	}
	return node->value;
}

template<class T1 , class T2>
int Unordered_map<T1,T2>::size()
{
	return size_;
}

