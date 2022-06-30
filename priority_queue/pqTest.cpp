#include<iostream>
#include"Priority_q.h"
using namespace std;

int main()
{
	Priority_queue<int> pq;
	int n,t;
	cin>>n;

	for(int i=0 ; i<n ; i++)
	{
		cin>>t;
		pq.push(t);
	}


	while(pq.size())
	{
		cout<<pq.pop()<<" ";
	}


}
