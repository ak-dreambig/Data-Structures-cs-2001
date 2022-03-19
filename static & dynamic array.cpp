#include<iostream>
using namespace std;

int main()
{
	int array[4]={1,2,3,4};

	cout<<"Static array : "<<endl;
	cout<<"printing using Index : "<<endl;
	
	for(int i=0;i<4;i++)
	{
		cout<<"\t"<<array[i];
	}	
	
	cout<<endl;
	
	cout<<"now printing using pointers : "<<endl;
	
	int *ptr=array;
	for(int i=0;i<4;i++)
	{
		cout<<"\t"<<*ptr++;
	}
	cout<<endl;
	
	cout<<"\n\ndynamic array : "<<endl;
	int n=4;
	int  *array2=new int[n];
	array2[0]=1;
	array2[1]=2;
	array2[2]=3;
	array2[3]=4;
	
	cout<<"printing using index : "<<endl;
	
	for (int i=0;i<4;i++)
	{
		cout<<"\t"<<array2[i];
	}
	cout<<endl;
	
	cout<<"\n\n priting using pointer : "<<endl;
	int *ptr2=array2;
	for(int i=0;i<4;i++)
	{
		cout<<"\t"<<*ptr2++;
	}
	cout<<endl<<endl<<endl;
	
	delete array2;
	cout<<"Changing the size of the dynamic array : ";
	array2=new int [10];
	array2[0]=1;
	array2[1]=2;
	array2[2]=11;
	array2[3]=12;
	array2[4]=13;
	array2[5]=14;
	array2[6]=15;
	array2[7]=16;
	array2[8]=17;
	array2[9]=18;
	
	cout<<endl;
	
	cout<<"printing using index : "<<endl;
	for(int i=0;i<9;i++)
	{
		cout<<"\t"<<array2[i];
	}
	
	delete []array2;
	return 0;
	
	
	
	
}
