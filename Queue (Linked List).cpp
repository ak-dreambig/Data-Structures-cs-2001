#include<iostream>
using namespace std;


struct node{
    int data;
    node *next;
    
};

class queuelist
{
    private:
        node *front , *rear , *temp;
        int count , limit;

    public:
        queuelist()
        {
            front=rear=temp=NULL;
            count =0;
            cout<<"Enter limit : ";
            cin>>limit;
        }

        void enqueue()
        {
            
            if(rear==NULL)
            {
                rear=new node;
                cout<<"Enter data : ";
                cin>>rear->data;
                front=rear;
                front->next=NULL;
                rear->next=NULL;
                count++;
                return; 
            }
            else
            {
                temp=new node;
                cout<<"Enter data : ";
                cin>>temp->data;
                rear->next=temp;
                rear=temp;
                rear->next=NULL;
                count++;
            }

        }

        void  dequeue()
        {
            
            isempty();

                temp=front;
                temp=temp->next;
                delete front;
                front=temp;
                count--;
                
            
        }

        void isempty()
        {
            if(front==NULL && rear==NULL)
            {
                cout<<"Empty!!"<<endl;
            }
            else
            cout<<"Not Empty!!";
        }

        void isfull()
        {
            if(count==limit)
            {
                cout<<"Fulll!!"<<endl;
            }
            else
            cout<<"Not Full!!";
        }
        void print()
        {
            temp=front;
            while(temp!=NULL)
            {
                cout<<temp->data<<"  ";
                temp=temp->next;
            }

       }



};


int main()
{
    queuelist q;
    
    q.enqueue();
    q.enqueue();
    q.enqueue();
    q.isfull();
    q.print();
    cout<<endl;
    q.dequeue();

    cout<<endl<<"After dequeue!!"<<endl;
    q.print();
    
}
