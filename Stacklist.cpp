#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class Stacks{
    private: 
    node *temp,*top;
    int count;
    int limit;

    public:
    Stacks(){
        top=temp=NULL;
        count=0;
        cout<<"Enter limit : ";
        cin>>limit;

    }

    void push(){
        if (count == limit )
        {
            cout<<"Over flow ";
            return;
        }
        else
        {
            temp=top;
        temp = new node;
        cout<<"Enter eliment : ";
        cin>>temp->data;
        temp->next=top;
        top=temp;
        count++;

        }

    }

    void pop(){
        if (count==0)
        {
            cout<<"Overflow ";
            return;

        }
        else
        {
            temp=top;
            top=top->next;
            delete temp;
            temp=NULL;
            count--; 

        }
    }
    void print(){
        temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data;
            temp=temp->next;
        }
    }


};

int main()
{
    int i;
    Stacks s;
    	cout<<"options : "<<endl;
    	
        cout<<"1 for push"<<endl;
    	cout<<"2 for pop"<<endl;
    	cout<<"3 for print"<<endl;
    	cin>>i;
    while(i!=4)
    {


        if(i==1)
        {
            s.push();
        }
        if(i==2)
        {
            s.pop();
        }
        if(i==3)
        {
            s.print();
        }
        cout<<" Option : ";
    cin>>i;
    }
}

