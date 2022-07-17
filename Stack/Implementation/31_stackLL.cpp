#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    int isFull();
    int isEmpty();
    int push(int d);
    int pop();
    int peek(int p);
    int stackTop();
    int stackBottom();
    void traverse();
};
Node *top = NULL;

int Node::isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
int Node::isFull()
{
    Node *ptr = new Node();
    if (ptr == NULL)
    {

        return 1;
    }
    return 0;
}
int Node::push(int d)
{
    if (isFull())
    {
        cout << "Stack OverFlow" << endl;
        return -1;
    }

    Node *ptr = new Node();
    ptr->data = d;
    ptr->next = top;
    top = ptr;
        return 0;

}
int Node::pop()
{
    if (isEmpty())
    {
        cout << "Stack UnderFLow" << endl;
        return -1;
    }

    Node *ptr = top;
    top = top->next;
    int p = ptr->data;
    cout << "Poped Element " << p << endl;
    free(ptr);
    return p;
}
int Node::stackTop()
{
    if (top==NULL)
    {
        return -1;
    }
    return top->data;
}

int Node::stackBottom()
{
    Node *ptr =top;
    while (ptr->next != NULL)
    {
        // cout << "Element : " << ptr->data << endl;
        ptr = ptr->next;
    }

    return ptr->data;
}

void Node::traverse()
{
    Node *ptr =top;
    while (ptr != NULL)
    {
        cout << "Element : " << ptr->data << endl;
        ptr = ptr->next;
    }
}
int Node::peek(int p)
{
    Node *ptr = top;
    // ptr->data = d;
    // ptr->next = top;
    // top = ptr;
    for (int i = 0; i < p-1; i++)
    {
        ptr=ptr->next;
    }
        return ptr->data;
}

int main()
{
    top->push(7);
    top->push(17);
    top->push(27);

    top->traverse();

    // top->pop();
    cout<<"stack top "<<top->stackTop()<<endl;
    cout<<"stack bottom "<<top->stackBottom()<<endl;
    cout<<"peek "<<top->peek(1)<<endl;
    cout<<"peek 2"<<top->peek(2)<<endl;
    cout<<"peek 3"<<top->peek(3)<<endl;

    // top->traverse(); 
    return 0;
}