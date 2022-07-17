#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *top = NULL;

int isEmpty(Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
};

int isFull()
{
    Node *p = new Node;
    if (p == NULL)
    {
        return 1;
    }
    return 0;
};

Node *push(Node *top, int p)
{
    if (isFull())
    {
        cout << "Stack Overflow";
        return 0;
    }
    Node *ptr = new Node;
    ptr->data = p;

    ptr->next = top;
    top = ptr;
    return top;
}

int pop(Node *tp)
{
    if (isEmpty(tp))
    {
        cout << "Stack is empty";
        return -1;
    }
    else
    {
        Node *ptr = tp;
        int xe = ptr->data;
        top = tp->next;
        free(ptr);

        return xe;
    }
}
void LinkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element is " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    top = push(top, 5);
    top = push(top, 54);
    top = push(top, 54544);
    top = push(top, 3);
    int j = pop(top);
    cout << j << endl;

    LinkedListTraversal(top);

    return 0;
}