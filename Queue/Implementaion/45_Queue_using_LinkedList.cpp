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

    void enqueue(int x)
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

    void deque()
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
    p.enqueue(5);
    p.enqueue(555);
    p.enqueue(555345);
    p.deque();
    p.deque();
    p.deque();
    p.deque();
    // p.deque();
    // p.deque();
    // p.deque();
    p.enqueue(44);
    p.enqueue(44);
    p.enqueue(44);
    p.enqueue(44);
    p.enqueue(44);
    p.deque();
    p.deque();
    p.deque();
    p.deque();
    p.deque();
    p.deque();
    p.deque();
    p.deque();

    p.LinkedListTraversal();
    return 0;
}