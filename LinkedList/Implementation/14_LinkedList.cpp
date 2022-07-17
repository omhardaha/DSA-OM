#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};


class Stack
{
public:
    Node *top;
    void push(int item)
    {
        Node *n = new Node;
        n->data = item;
        n->next = top;
        top = n;
    }
    void pop()
    {
     Node *ptr = top;
    top = top->next;
    // free(ptr);
    delete ptr;
//    top =;
top = top;
    }
};

int main()
{

    Stack s;

    s.push(53);
    s.push(335);
    s.pop();

    cout << s.top->data;
    // cout << s.top->data;

    return 0;
}