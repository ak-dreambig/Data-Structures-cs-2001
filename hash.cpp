#include<iostream>
#include<list>

using namespace std;

class Hash{
	int capacity;
	list<int> *table;
	
	public:
		Hash(int v);
		void insertItem(int key, int data);
		void deleteItem(int key, int data);
		int checkprime(int n)
		{
			int i;
			if(n==1 || n==0)
			{
				return 0;
			}
			
			for(i=2;i<n/2;i++)
			{
				if(n%i == 0)
				{
					return 0;
				}
			}
			return 1;
		}
		int getprime(int n)
		{
			if(n%2==0)
			{
				n++;
			}
			while (!checkprime(n))
			{
				n +=2;
			}
			return n;
		}
		int hashfunc(int key)
		{
			return (key % capacity);
		}
		void displayhash();
};
Hash :: Hash(int c)
{
	int size = getprime(c);
	this->capacity = size;
	table = new list<int>[capacity];
}
void Hash::insertItem(int key, int data)
{
	int index = hashfunc(key);
	table[index].push_back(data);
}

void Hash::deleteItem(int key,int data)
{
	int index = hashfunc(key);
	
	list<int>::iterator i;
	for(i = table[index].begin();i != table[index].end();i++)
	{
		if(*i == key)
			break;
	}
	
	if(i != table[index].end())
	{
		table[index].erase(i);
	}
}

void Hash::displayhash()
{
	for (int i = 0; i < capacity; i++)
	{
		cout<<"table["<< i << "]";
		for(auto x : table[i])
			cout<<"-->"<<x;
			
		cout<<endl;
	}
};

int main()
{
	int key[]={231,321,212,321,433,262};
	int data[]={123,432,532,42,423,111};
	int size = sizeof(key)/sizeof(key[0]);
	
	Hash h(size);
	
}
