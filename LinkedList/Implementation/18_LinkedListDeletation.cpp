#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
void LinkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element is " << ptr->data << endl;
        ptr = ptr->next;
    }
}


Node *DeletationTheFirstNode(Node *Head)
{
    Node *ptr = Head;

    Head = Head->next;
    // free(ptr);
    delete ptr;
    return Head;
}

Node *DeletationInIndex(Node *Head, int Index)
{
    Node *P = Head;
    int i = 0;
    while (i != Index - 1)
    {
        P = P->next;
        // cout<<P->data;
        i++;
    }

    Node *P2 = P->next;

    P->next =P2->next;
    
    delete P2;

    return Head;
}


//CWD method
// Node *DeletationInIndex(Node *Head, int Index)
// {
//     Node *P = Head;
//     Node *P2 = P->next;
//     int i = 0;
//     for (int i = 0; i < Index-1; i++)
//     {
//         P= P->next;
//         P2= P2->next;
//     }
//  P->next =P2->next;
//     delete P2;

//     return Head;
// }


Node *DeletationLastElement(Node *Head)
{
    Node *P = Head;
    Node *P2 = P->next;
    // int i = 0;
    while (P2->next != NULL)
    {
        P = P->next;
        P2 = P2->next;
        // cout<<P->data;
        // i++;
    }
     P->next = NULL;
    delete P2;
    // P->next =P2->next;
    return Head;
}

Node *DeletingTheElementWithGivenValue(Node *Head, int Value)
{
    Node *P = Head;
    Node *P2 = P->next;

    while (P2->data != Value && P2->next!=NULL) 
    { P = P->next;
        P2 = P2->next;
        // cout<<P->data;
    }
    if (P2->data == Value)
    {
        P->next =P2->next;
    delete P2;
    }
    return Head;
}


int main()
{

    Node *Head = new Node;
    Node *Second = new Node;
    Node *Third = new Node;
    Node *Fourth = new Node;

    Head->data = 7;
    Head->next = Second;

    Second->data = 17;
    Second->next = Third;

    Third->data = 107;
    Third->next = Fourth;

    Fourth->data = 4444;
    Fourth->next = NULL;

    LinkedListTraversal(Head);
    cout << endl
         << "After Deletationn ->" << endl;

    // Head = DeletationTheFirstNode(Head);
    // Head = DeletationInIndex(Head, 2);
    // Head = DeletationLastElement(Head);
    Head = DeletingTheElementWithGivenValue(Head,17);

    LinkedListTraversal(Head);

    return 0;
}