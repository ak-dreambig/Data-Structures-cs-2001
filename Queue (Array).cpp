#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
};

class ArrayQueue
{
    private:

        int *arr, *front, *rear, *temp;
        int size=5; // Array size.

    public:

        ArrayQueue()
        {
            

            arr = new int[size];
            front = NULL;
            rear = NULL;
            temp = NULL;
        }

        // Insertion
        void enqueue( int num)
        {
            // Insertion if array is empty / First insert.
            if ( front == NULL)
            {
                front = rear = arr;
                *rear = num;

                cout << "\n" << num << " inserted to queue." << endl;
                return;
            }

            // If Queue ( Array) is FULL.
            if ( ( front == arr && rear == arr + ( size - 1) ) || rear == front - 1)
            {
                cout << "\nQueue is full." << endl;
                return;
            }

            // If Rear is at the end of array move it to the start of array and store data in it.
            if ( rear == arr + ( size - 1))
            {
                rear = arr;
                *rear = num;

                cout << "\n" << num << " inserted to queue." << endl;
                return;
            }

            // If none of these cases are True then just move rear forward and store data in it.
            rear++;
            *rear = num;

            cout << "\n" << num << " inserted to queue." << endl;
            return;
        }

        void dequeue()
        {
            if ( front == NULL)
            {
                cout << "\nQueue Array is empty." << endl;
                return;
            }

            // For 1 node
            if ( front == rear)
            {
                cout << "\nDequeue: " << *front << endl;
                front = NULL;
                rear = NULL;
                return;
            }

            if ( front == arr + ( size - 1))
            {
                cout << "\nDequeue: " << *front << endl;
                front = arr;
                return;
            }
            cout << "\nDequeue: " << *front << endl;
            front++;

        }

        void print()
        {
            if ( front == NULL)
            {
                cout << "\nQueue Array is empty. Cannot print." << endl;
                return;
            }

            temp = front;
            cout << "\nFront -> ";
            
            while ( temp != rear)
            {
                if ( temp == arr + ( size - 1))
                {
                    cout << *temp << "\t";
                    temp = arr;
                }

                cout << *temp << "\t";
                temp++;
            }
            cout << *temp << " <- Rear" << endl;
            temp = NULL;
        }
};

int main()
{
    ArrayQueue q;
    q.dequeue();

    
    q.enqueue( 1);
    q.enqueue( 2);
    q.enqueue( 3);
    q.enqueue( 4);
    q.enqueue( 5);
    q.print();
    q.dequeue();
    q.dequeue();
    q.enqueue( 7);
    q.enqueue( 8);
    q.print();
}
