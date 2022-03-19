#include <iostream>
#include <stddef.h>
using namespace std;
struct node
{
    int data;
    node *next,*previous;
};

 class doubluelinklistop
 {
 private:
    node *head,*temp,*temp1;
    int key;
 public:
    doubluelinklistop()
    {
        head=temp=temp1=NULL;
    }
    void add()
    {
        if(head==NULL)
        {
            head=new node;
            cout<<"Enter element you want to add : ";
            cin>>head->data;
            head->previous=NULL;
            head->next=NULL;
            return;
        }
        else
        {
            temp=head;
            cout<<"After which element you want to add : ";
            cin>>key;

            while(temp!=NULL)
            {
                if(temp->data==key)
                {
                    if(temp->next==NULL)
                    {
                        temp1=new node;
                        cout<<"Enter element you want to add : ";
                        cin>>temp1->data;
                        temp->next=temp1;
                        temp1->previous=temp;
                        temp1->next=NULL;
                    }
                    else
                    {


                    temp1=new node;
                    cout<<"Enter element you want to add : ";
                    cin>>temp1->data;
                    temp1->next=temp->next;
                    temp->next->previous=temp1;


                    temp->next=temp1;
                    temp1->previous=temp;
                    }


                }
                temp=temp->next;
            }

        }
    }
    void print()
    {
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
    }
    void removeElement()
    {
        if(head==NULL)
        {
            cout<<"empty!!!!"<<endl;
            return;

        }
        if(head->next==NULL && head->previous==NULL)
        {
            delete head;
            head=NULL;
            return;
        }
        else
        {
            temp=head;
            cout<<"Which element you want to delete?"<<endl;
            cin>>key;
            while(temp!=NULL)
                  {
                    if(temp->data==key)
                    {
                        if(temp==head)
                        {
                            head=temp->next;
                            head->previous=NULL;
                            delete temp;
                            return;
                        }
                        if(temp->next==NULL) //if tem is at end of list
                        {
                            temp->previous->next=NULL;
                            delete temp;
                            return;
                        }
                        else
                        {


                        temp->previous->next=temp->next;
                        temp->next->previous=temp->previous;
                        delete temp;
                        temp=head;
                        }
                    }
                    temp=temp->next;
                  }

        }
    }

 };
int main()
{
    doubluelinklistop d2;
    int i;
    cout<<"Enter option"<<endl;
    cout<<" 1 for add."<<endl;
    cout<<" 2 for print."<<endl;
    cout<<" 3 for remove."<<endl;
    cin>>i;
    while(i!=4)
    {
        if(i==1)
            d2.add();
        if(i==2)
            d2.print();
        if(i==3)
            d2.removeElement();
        cout<<"Enter option"<<endl;
        cin>>i;
    }
}
