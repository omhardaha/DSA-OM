#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    int top;
    int *arr;
    int isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {

            return 0;
        }
    };

    int isFull()
    {
        if (top == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };

    void push(int item)
    {
        if (isFull())
        {
            // return 0;
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[++top] = item;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
        
    }
    int peek(int i)
    {
        // if (i==0)
        // {
        //     cout<< "Not a valid position";
        // return arr[i];
        // }
        if (i<=0)
        {
            cout<< "Not a valid position"<<endl;
        return -1;
        }
        if (top-i+1<=0)
        {
            cout<< "Not a valid position"<<endl;
        return -1;
        }

        else{

            return arr[top-i+1];
        }
        
    }
};
int main()
{
    stack m;
    m.size = 6;
    m.top = -1;
    m.arr = new int[m.size];

    m.push(6);
    m.push(16);
    m.push(26);
    m.push(326);

    cout<<m.peek(3);

    return 0;
}