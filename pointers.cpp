#include<iostream>
using namespace std;


int main()
{
	int *p = NULL;
	 p= new (nothrow)int;
	 
	 if(!p)
	 {
		cout<<"memory not alloacted\n"; 	
	 }	
	 
	 else
	{
		*p=29;
		cout<<"value of p : "<<*p<<endl;
		
	}
	
	float *r = new float(75.25);
	cout<<"value of r : "<<*r<<endl;
	
	int n=5;
	int *q=new (nothrow)int [n];
	
	if(!q)
		cout<<"memmory not allocated\n";
	else
	{
		for(int i=0;i<n;i++)
			q[i]=i+1;
			cout<<"value store in block of memory using index : ";
			for(int i=0;i<n;i++)
			cout<<q[i]<<" ";
			cout<<endl<<"value store in block of memeory using ptr : ";
			
			for(int i=0;i<n;i++)
			{
				cout<<*q<<" ";
				q=q+1;
			}
	
	}
	delete p;
	delete r;
	delete []q;
	return 0;
}
