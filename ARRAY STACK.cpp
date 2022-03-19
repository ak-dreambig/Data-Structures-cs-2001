#include<iostream>
#include<cstddef>
using namespace std;

class stackk
{
	  private : 
	  int *top,*temp;
	  int *stk;
	  int size;
	  int *len;
	  
	  public: 
	  stackk()
	  {
	  	top=temp=NULL;
	  	cout<<"Enter size of an array: ";
	  	cin>>size;
	  	stk=new int[size];
	  }
	  void push()
	  {
	  	
		if(top==NULL)
		{
				top=stk;
				cout<<"Enter elemnt : ";
				cin>>*top;
				return;
		}
			
		

		len=stk+size-1;
		if(len==top)
	  	{
	  		"cout<<overflow";
	  		return;
		}
		else
		{
			top++;
			cout<<"Enter elemnt : ";
			cin>>*top;	
		}
	}
		void pop()
		{
		
			if (top==NULL)
			{
				cout<<"Underflow";
				return;
			}
			if(top==stk)
			{
				top==NULL;
				return;
			}
			else
			{
				top--;
			
			}
			
		}
		void print()
		{
			 while(top!=NULL)
			 {
			 	cout<<*top<<"   ";
			 	pop();
			 }
		}
};

int main()
{

	stackk s;
	int j;
	cout<<"Options : "<<endl;
	cout<<"1 for push."<<endl;
	cout<<"2 for pop."<<endl;
	cout<<"3 for print."<<endl;
	
	cin>>j;
	while(j!=4)
	{
		if(j==1)
		{
			s.push();
		}
		if(j==2)
		{
			s.pop();
		}
		if(j==3)
		{
			s.print();
		}
		cout<<"Options : ";
	cin>>j;
	}
	
}
