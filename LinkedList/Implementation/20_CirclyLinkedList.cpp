#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// void LinkedListTraversal(Node* Head){
//    while (Head != NULL){
// cout<<"Element : " <<Head->data<<endl;
//      Head=Head->next;}}

void CirculyLinkedListTraversal(Node *Head)
{
    Node *ptr = Head;
    do
    {
        cout << "Element : " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != Head);
}

Node *InsertAtFirst(Node *Head, int element)
{
    Node *InsertNode = new Node;
    InsertNode->data = element;

    Node *P = Head;
    while (P->next != Head)
    {
        P = P->next;
    };

    P->next = InsertNode;
    InsertNode->next = Head;

    // Head = InsertNode;
    return InsertNode;
};

Node *InsertAtGivenIndex(Node *Head, int element, int index)
{

    Node *ptr = new Node;
    ptr->data = element;

    Node *P = Head;

    for (int i = 0; i < index - 1; i++)
    {
        P = P->next;
    }
    ptr->next = P->next;
    P->next = ptr;
    return Head;
};

Node *InsertAtEnd(Node *Head, int element)
{

    Node *ptr = new Node;
    ptr->data = element;

    Node *P = Head;

    while (P->next != Head)
    {
        P = P->next;
    }

    P->next = ptr;
    ptr->next = Head;

    return Head;
};

void InsertAtAfterGivenNode(Node *GivenNode, int element)
{

    Node *ptr = new Node;
    ptr->data = element;

    ptr->next = GivenNode->next;
    GivenNode->next = ptr;

    //  return Head;
};

int main()
{
    Node *Head = new Node;
    Node *Second = new Node;
    Node *Third = new Node;
    Node *Fourth = new Node;

    Head->data = 10;
    Head->next = Second;

    Second->data = 20;
    Second->next = Third;

    Third->data = 30;
    Third->next = Fourth;

    Fourth->data = 40;
    Fourth->next = Head;

    CirculyLinkedListTraversal(Head);

    cout << endl
         << "After Insertion - " << endl;

    // Head = InsertAtFirst( Head,34);
    // Head = InsertAtGivenIndex( Head,2222,3);
    // Head = InsertAtEnd( Head,22223);
    InsertAtAfterGivenNode(Second, 22223);

    CirculyLinkedListTraversal(Head);

    return 0;
}