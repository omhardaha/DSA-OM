#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class QueueNode
{
public:
    Node *front = NULL;
    Node *rear = NULL;

    void enqueueBack(int x)
    {
        Node *ptr = new Node();
        if (ptr == NULL)
        {
            cout << "Queue is Full!" << endl;
        }
        else
        {
            ptr->data = x;
            if (rear == NULL)
            {
                rear = front = ptr;
            }
            else
            {
                rear->next = ptr;
                rear = ptr;
            }
            cout << "enqued Element: " << x << endl;
        }
    }
    void enqueueFront(int x)
    {
        Node *ptr = new Node();
        if (ptr == NULL)
        {
            cout << "Queue is Full!" << endl;
        }
        else
        {
            ptr->data = x;

            if (rear == NULL)
            {
                rear = front = ptr;
            }
            else
            {
                ptr->next = front;
                front = ptr;
            }
            cout << "enqued Element: " << x << endl;
        }
    }

    void dequeFront()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            Node *ptr = front;
            cout << "dequed Element: " << ptr->data << endl;
            front = front->next;

            if (front == NULL)
            {
                rear = NULL;
            }

            free(ptr);
        }
    }
    void dequeBack()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            Node *ptr = rear;
            cout << "dequed Element: " << ptr->data << endl;
            front = front->next;

            if (front == NULL)
            {
                rear = NULL;
            }

            free(ptr);
        }
    }
    void LinkedListTraversal()
    {
        Node *ptr = front;
        while (ptr != NULL)
        {
            cout << "Element is " << ptr->data << endl;
            ptr = ptr->next;
        }
    }
};

int main()
{
    QueueNode p;
    p.enqueueFront(434);
    p.enqueueFront(234);
    p.enqueueFront(34);

    p.enqueueBack(45);

    p.dequeFront();

    p.LinkedListTraversal();
    return 0;
}