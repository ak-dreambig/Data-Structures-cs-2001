#include<iostream>
using namespace std;

class arraylist
{
    private:
        int size;
        int length;
        int pos;
        int *array;
        int *curr;

    public:
        arraylist(){
            size=10;
            array=new int[size];
            length=0;
            pos=0;
            curr=array;
        }

        ~arraylist()
        {
            delete []array;

        }

        void printarray()
        {
            if(length>0)
            {
                head();
                for(int i=0;i<length;i++)
                cout<<*curr++<<"   ";
            }
            else
                cout<<"Array is full.";
        }

        void insertelement(int val)
        {
            if(!isfull())
            {
                head();
                curr=curr+length;
                *curr=val;
                length++;

            }
            else 
                cout<<"Array is full";
        }

        void insertatpos(int val,int pos)
        {
            if(pos<=length && pos>0)
            {
                tail();
                for(int i=length;i>=pos;i--)
                {
                    *(curr+1)=*curr;
                    curr=curr+1;
                }
                next();
                *curr=val;
                length++;
            }
            else if(pos>length && pos<=size)
            {
                head();
                curr=curr+pos-1;
                *curr=val;
                length++;
            }     
            else
                cout<<"Invalid Position."  ;     
        }

        void reversearray()
        {
            int *p1,*p2,temp;

            p1=array;
            p2=array+size-1;
            int val=size/2;
            for(int i=0;i<val;i++)
            {
                temp=*p1;
                *p2=*p1;
                *p2=temp;
                p1++;
                p2--;
            }
        }

        void deleteatpos(int pos)
        {
            if(!isempty())
            {
                
                if(pos<=size && pos>0)
                {
                    head();
                    curr=curr+pos-1;
                    for(int i=0;i<length;i++)
                    {
                        *curr = *(curr+1);
                        next();
                    }

                }
            }
        }

        void tail()
        {
            curr=array+length-1;
    
        }

        void back()
        {
            curr=curr-1;

        }
        void next()
        {
            curr=curr+1;
        }
        int lengtharray()
        {
            return length;
        }

        bool isempty()
        {
            if(length==0)
            {
                return true;
            }
            else 
                return false;
        }

        void head()
        {
            curr=array;
        }

        bool isfull()
        {
            if(length==size)
            {
                return true;
            }
            else
                return false;
        }


};


int main()
{
    arraylist l;
    l.isempty();
    l.insertelement(2);
    l.insertelement(4);
    l.insertelement(5);
    l.insertatpos(23,4);
    l.printarray();
    cout<<endl;
    cout<<"After deletion:"<<endl;
    l.deleteatpos(3);
    l.printarray();
}
