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
};
int main()
{
    stack m;
    m.size = 6;
    m.top = -1;
    m.arr = new int[m.size];

    cout << m.isEmpty() << endl;
    cout << m.isFull() << endl;
    m.push(5);
    // m.push(5);
    // m.push(5);
    // m.push(5);
    // m.push(5);
    // m.push(5);
    m.pop();
    cout << m.isEmpty() << endl;
    cout << m.isFull() << endl;
    // m.pop();
    // cout << m.isEmpty()<<endl;
    // cout << m.isFull()<<endl;
    // m.push(5);
    // m.push(5);
    // cout << m.isEmpty()<<endl;
    // cout << m.isFull()<<endl;

    return 0;
}