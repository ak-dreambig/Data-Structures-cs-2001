#include <iostream>
using namespace std;
class arrayop
{
	private:
	int *p,*q;
	int *a;
	int sizes;
	int num;
	int elem;
	int ad;
	int checkcount=0;
	public:
	arrayop()
	{
		
		cout<<"Enter size of array : ";
		cin>>sizes;
		a=new int[sizes];   //dynamic array	
		q=p=a;	
		}	
		void get()
		{
			cout<<*p;
		}
		void update()
		{
			cout<<"Enter the number : ";
			cin>>num;
			cout<<"With which element : ";
			cin>>elem;
			p=a;
			for(int i=0;i<sizes;i++)
			{
				if(*p==elem)
				{
					*p=num;
					return;
				}
				p++;
			}
		}
		void length()
		{
			cout<<checkcount;
		}
		void backs(){
			p--;
		}
		void next()
		{
			p++;
		}
		void start()
		{
			p=a; //p pointing a
		}
		void ends()
		{
			p=a+(sizes-1);
		}
		void add()
		{
			cout<<"What you want to add? ";
			cin>>ad;
			if(checkcount<=sizes)
			{
			
			*p=ad;
			p++;
		}
		else
		cout<<"Array out of bound";
			checkcount++;
		}
		void print()
		{
			q=a;
			for(int i=0;i<sizes;i++)
			{
				cout<<*p<<" ";
				p++;
			}
			cout << "l" << checkcount;
		}
		
		
};
int main()
{
	arrayop a;
	int b;
	cout<<"Enter elements :";
	cin>>b;
	while(b!=3){
	
	cout<<"Enter b";
	cin>>b;
	if(b==1)
	{
		a.add();
	}
	else if(b==2)
	{
		a.print();
	}
}
}
