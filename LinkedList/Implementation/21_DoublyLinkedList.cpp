#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void LinkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element is " << ptr->data << endl;
        ptr = ptr->next;
    }
};
void LinkedListReverseTraversal(Node *ptr)
{
    Node *ptr1 = ptr;
    while (ptr1->next != NULL)
    {
        cout << "Element is " << ptr1->data << endl;
        ptr1 = ptr1->next;
    }
    cout << endl;
    while (ptr1 != NULL)
    {
        cout << "Element is " << ptr1->data << endl;
        ptr1 = ptr1->prev;
    }
};

Node *insertAtFirst(Node *head, int x)
{
    Node *ptr = new Node;
    ptr->data = x;
    ptr->next = head;
    return ptr;
};

Node *insertAtIndex(Node *head, int x, int index)
{
    Node *ptr = new Node;

    Node *P = head;
    int i = 0;
    while (i != index - 1)
    {
        P = P->next;
        i++;
    }

    ptr->next = P->next;
    P->next = ptr;
    ptr->data = x;

    return head;
};

Node *insertAtEnd(Node *head, int x)
{
    Node *ptr = new Node;
    Node *P = head;
    int i = 0;
    while (P->next != NULL)
    {
        P = P->next;
        i++;
    }
    ptr->next = P->next;
    P->next = ptr;
    ptr->data = x;
    return head;
};

void insertAtGiven(Node *GivenNode, int x)
{
    Node *ptr = new Node;
    ptr->data = x;

    ptr->next = GivenNode->next;
    GivenNode->next = ptr;
};

int main()
{

    Node *Head = new Node;
    Node *Second = new Node;
    Node *Third = new Node;
    Node *Fourth = new Node;

    Head->data = 10;
    Head->next = Second;
    Head->prev = NULL;

    Second->data = 20;
    Second->next = Third;
    Second->prev = Head;

    Third->data = 30;
    Third->next = Fourth;
    Third->prev = Second;

    Fourth->data = 40;
    Fourth->next = NULL;
    Fourth->prev = Third;

    // LinkedListTraversal(Head);
    LinkedListReverseTraversal(Head);

    cout << endl;
    //  << "afterinsertion - " << endl;
    // Head = insertAtFirst(Head, 666);
    // Head = insertAtIndex(Head, 666,3);
    // Head = insertAtEnd(Head, 666);
    // insertAtGiven(Second, 666);
    // LinkedListTraversal(Head);

    return 0;
}