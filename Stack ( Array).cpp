#include <iostream>
using namespace std;

class stack
{
    int *top, *stk;
    int size = 0;

    public:

        stack()
        {
            top = NULL;

            cout << "Enter Stack (Array) size: ";
            cin >> size;

            stk = new int[size];
        }

        void push( int x)
        {
            if ( top == NULL)
            {
                top = stk;
                *top = x;
                return;
            }

            if ( top == stk + ( size - 1))
            {
                cout << "\nStack overflow." << endl;
                return;
            }

            top++;
            *top = x;
        }

        void pop()
        {
            if ( top == NULL)
            {
                cout << "\nStack underflow." << endl;
                return;
            }

            if ( top == stk)
            {
                top = NULL;
                return;
            }

            top--;
        }

        void peek()
        {
            cout << "\n" << *top << endl;
        }

        void print()
        {
            while ( top != NULL)
            {
                cout << *top << "\t";
                pop();
            }
        }
};

int main()
{
    stack s1;
    s1.push( 1);
    s1.push( 2);
    s1.push( 3);
    s1.pop();
    s1.pop();
    s1.print();

}
