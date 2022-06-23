#include<iostream>

using namespace std;

template<class T>
class Vector
{
	T *arr;
	int capacity_;
	int size_;
	//static T* iterator
public:

	Vector();
	Vector(Vector<T> &);
	Vector(int);
	Vector(int,T);
	Vector(T*,T*);
	~Vector();
	int size();
	int capacity();
	void push_back(T);
	void pop_back();
	T* begin();
	T* end();
	T front();
	T back();
	void clear();
	T& operator[](int);
	void mkspace(int , bool);
	Vector<T>& operator +( Vector<T>&);
//	friend std::ostream& operator<< <T>(std::ostream&  , Vector<T>&);


};


//template<class T>
//std::ostream& operator<< <T>(std::ostream& , Vector<T>&);


//template<class T>
//std::ostream& operator<<(std::ostream& dout , Vector<T>& arr)
//{
//	for(int i=0 ; i<arr.size();i++)dout<<arr[i]<<" ";
//	return dout;
//}


template<class T>
T* Vector<T>::begin()
{
	return arr;

}

//.....................................................

template<class T>
T* Vector<T>::end()
{
	return arr+size_;
}

//.......................................................

template<class T>
Vector<T>:: ~Vector()
{
	if(!arr)
	{
		delete[] arr;
	}
}
//.......................................................
template<class T>
Vector<T>& Vector<T>::operator+( Vector<T> &second )
{
	int n1 = size_;
	int n2 = second.size();

	static Vector<T> newVector;

	for(int i=0 ; i<n1 ; i++)newVector.push_back(arr[i] );
	for(int i=0 ; i<n2 ; i++)newVector.push_back(second[i]);

	return newVector;

}
//....................................................

template<class T>
Vector<T>::Vector()
{
	capacity_ = 0;
	size_ = 0;
	arr = 0;
}

//......................................................
template<class T>
Vector<T>::Vector(Vector<T> &v)
{
	size_ = capacity_ = v.size_;
	arr = new T[size_];

	for(int i=0 ; i<size_ ; i++)
		arr[i] = v[i];
}

//......................................................

template<class T>
Vector<T>::Vector(T* start , T* end)
{
	size_ = capacity_ = end-start;

	arr = new T[size];
	T* ptr = start;

	int i=0;
	while(ptr != end)
	{
		arr[i++]=*ptr;
		ptr++;
	}
}

//.....................................................

template<class T>
Vector<T>::Vector(int n , T fill)
{
	capacity_ = size_ = n;
	arr = new T[n];

	for(int i=0 ; i<n ; i++)arr[i]=fill;
}

//......................................................

template<class T>
int Vector<T>::size()
{
	return size_;
}

//......................................................
template<class T>
int Vector<T>::capacity()
{
	return capacity_;
}

//.....................................................

template<class T>
void Vector<T>::mkspace(int n , bool sig)
{
	T *newArray = new T[n];

	if(newArray==NULL)
	{
		cout<<"Memory allocation Error !";
		return;
	}
	if(sig)//there is element in arr
	{
		for(int i=0 ; i<size_ ; i++)
			newArray[i]=arr[i];
	}

	if(arr!=NULL)
		delete[] arr;

	arr = newArray;

}

//...................................................

template<class T>
void Vector<T>::push_back(T elem)
{
	if(capacity_==size_)
	{
		if(capacity_==0)
		{
			mkspace(1,0);
			capacity_ = 1;
		}
		else
		{
			mkspace(2*capacity_,1);
			capacity_*=2;
		}
	}

	arr[size_]=elem;
	size_++;

}

//.....................................................

template<class T>
void Vector<T>::pop_back()
{
	if(arr!=NULL)
	size_--;
}

//......................................................

template<class T>
T& Vector<T>::operator[](int i)
{
	return arr[i];
}

//......................................................

template<class T>
T Vector<T>::front()
{

	if(arr==NULL) return NULL;
		return arr[0];

}

//.......................................................

template<class T>
T Vector<T>::back()
{
	if(arr==NULL) return NULL;
		return arr[size_-1];
}

//........................................................

template<class T>
void Vector<T>::clear()
{
	if(arr == NULL)return;
	delete[] arr;
	size_=0;
	capacity_=0;
}

//.........................................................

