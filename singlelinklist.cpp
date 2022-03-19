#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;

};

class linkedlist{
    private:

node *head,*temp,*temp1,*temp2;
int key,num,delnum;

public:

linkedlist(){
    head=temp=temp1=temp2=NULL;


}
void add()
{
    bool check= false;
    if (head == NULL)
    {
    	
        head= new node;

        cout<<"Enter element: ";
        cin>>head->data;
        head->next=NULL;

    }
    else if (head!=NULL)
    {
        cout<<"What you want to add: ";
        cin>>num;
        cout<<"After which element you want to add: ";
        cin>>key;
        temp=head;
        while(temp!=NULL)
        {
            if (temp->data == key)
            {
                temp1 = new node;
                temp1->data=num;
                temp1->next=temp->next;
                temp->next=temp1;
                cout<<"Element Added sucessfully"<<endl;
                check = true;

            }
            temp=temp->next;
        }
        if (check == false)
        {
            cout<<"Key not found";

        }

    }
}
void print()
{
    temp=head;
    if (head == NULL)
    {
    	cout<<"linked is list empty!!"<<endl;
	}
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
}

void remove()
{
    bool check=false;
    cout<<"Which element you want to delete: ";
    cin>>delnum;
    temp = head;
    if (head==NULL)
    {
        cout<<"link list is empty: "<<endl;

    }
    else if (head!=NULL)
    {
        if (head->data==delnum)
        {
            head=head->next;
            delete temp;
            temp=NULL;
        }

        while (temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                if (temp->next->data==delnum)
                {
                    temp1=temp->next;
                    temp->next=temp->next->next;
                    delete temp1;
                    temp1=NULL;
                    check =true;
                }
                temp=temp->next;
            }
            
        }
        
    }
    if(check==false)
        {
            cout<<"Element not found"<<endl;
        }

}

void searching()
{
	int search;
	int count = 1;
	cout<<"Enter elemnt to search for : ";
	cin>>search;
	temp=head;
	if(head->data==search)
	{
		cout<<"Element found in head  "<<endl;
	}
	if(head->data!=search)
	{
		while (temp->next!=NULL)
		{
			if(temp->data==search)
			{
				cout<<"element found in node "<<count<<endl;
			}
			count++;
			temp=temp->next;
		}
		
	}
}
 
void swap()
{
 	int n1, n2;
 	cout<<"Enter nodes you want to swap : "<<endl;
 	cout<<"node 1 : "; cin>> n1;
 	cout<<"node 2 : "; cin>> n2;
 	temp=temp1=temp2=head;
 	if (head==NULL)
 	{
 		cout<<"linked list empty!!"<<endl;	
	}
	if (head!=NULL)
	{
		if(head->next==NULL)
		{
			cout<<"only one node in the list."<<endl;
		}
		if(head->next!=NULL)
		{
			while(temp->next!=NULL)
			{
				if(temp->data==n1)
				{
					while(temp1->next!=NULL)
					{
						temp1=temp1->next;
					}
				
				}
				if(temp->data==n1 && temp1->data==n2)
				{
					temp2->data=temp1->data;
					temp1->data=temp->data;
					temp->data=temp2->data;
					
					temp2=NULL;
					
			
				}
				temp=temp->next;
			}
		}
	}
}

void empty()
{
	if(head==NULL)
	{
		cout<<"List is Empty!!!"<<endl;
	}
}
 
 
 
};
int main()
{
    linkedlist l;
    int select;
    //cout<<"Enter option"<<endl;
    do
    {
    	cout<<endl;
        cout<<"Enter options"<<endl;
        cout<<"press 1 for add."<<endl;
        cout<<"press 2 for print."<<endl;
        cout<<"press 3 to delete."<<endl;
        cout<<"press 4  for searching."<<endl;
        cout<<"press 5 for swapping."<<endl;
        cout<<"press 6 to check whether the list id empty or not."<<endl;
        cout<<"========================================================================================================"<<endl;
        cin>>select;
        if(select==1)
            l.add();
        if(select==2)
            l.print();
        if(select==3)
            l.remove();
        if(select==4)
        {
        	l.searching();
		}
		if(select==5)
		{
			l.swap();
		}
		if(select==6)
		{
			l.empty();
		}
    }
    while(select!=7);
    
    

}



