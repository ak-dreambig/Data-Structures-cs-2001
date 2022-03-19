#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
};

class RingList
{
    Node *head, *temp;

    public:

        RingList()
        {
            head = NULL;
            temp = NULL;
        }

        void insert( int key)
        {
            if ( head == NULL)
            {
                head = new Node;
                head -> data = key;
                head -> prev = head;
                head -> next = head;

                return;
            }

            temp = head;

            do
            {
                temp = temp -> next;
            } while ( temp -> next != head);

            Node *temp1 = new Node;
            temp1 -> data = key;
            temp1 -> next = temp -> next;
            temp1 -> prev = temp;
            temp -> next = temp1;
            temp1 -> next -> prev = temp1;

            temp = NULL;
            return;
        }

        void deletion( int key)
        {
            if ( head == NULL)
            {
                cout << "\nList is empty." << endl;
                return;
            }

            temp = head;

            if ( head -> next == head)
            {
                if ( head -> data == key)
                {
                    delete head;
                    head = NULL;
                    return;
                }
            }

            temp = head;

            do
            {
                if ( temp -> data == key)
                {
                    Node *temp1 = temp -> prev;
                    temp1 -> next = temp -> next;
                    temp -> next -> prev = temp1;

                    if ( temp == head)
                        head = temp -> next;

                    delete temp;

                    temp = NULL;
                    return;
                }

                temp = temp -> next;
            }
            while ( temp != head);

            cout << "\nKey not found." << endl;

            temp = NULL;
            return;
        }

        void print()
        {
            if ( head == NULL)
            {
                cout << "\nList is empty." << endl;
                return;
            }

            temp = head;
            do
            {
                cout << temp -> data << "\t";
                temp = temp -> next;
            }
            while( temp != head);

            cout << endl;
            
            temp = NULL;
            return;
        }
};

int main()
{
    RingList l;

    l.insert( 1);
    l.insert( 2);
    l.insert( 3);
    l.insert( 4);
    l.insert( 5);

    l.print();

    l.deletion( 5);

    l.print();

}
