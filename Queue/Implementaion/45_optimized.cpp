#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        next = NULL;
        data = x;
    }
};

class Queue
{
public:
    Node *front, *rear;
    Queue()
    {
        front = rear = NULL;
    };

    void enqueue(int x)
    {
        Node *ptr = new Node(x);
        if (rear == NULL)
        {
            rear = front = ptr;
        }
        else
        {
            rear->next = ptr;
        }
        cout << "enqueued Element : " << x << endl;
    }
    void dequeue()
    {
        if (rear == NULL || ((front == NULL) && (rear == NULL)))
        {
            cout << "queue is empty!" << endl;
        }
        else
        {
            Node *ptr = front;
            cout << "dequeue is : " << front->data << endl;
            front = front->next;
            free(ptr);
            if (front == NULL)

            {
                rear = NULL;
            }
        }
    }

    void traverse()
    {
        Node *ptr = front;
        while (ptr != NULL)
        {
            cout << "element is : " << ptr->data << endl;
            ptr = ptr->next;
        }
    }
};
int main()
{
    class Queue p;
    p.enqueue(6);
    p.enqueue(90);
    p.traverse();
    p.dequeue();
    p.dequeue();
    p.dequeue();

    return 0;
}