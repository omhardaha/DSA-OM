#include <iostream>
using namespace std;

class Queue
{
public:
    int f = -1;
    int r = -1;
    int size;
    int *arr;
    Queue(int x)
    {
        size = x;
        arr = new int[x];
    }
    int isEmpty()
    {
        if (r<f)
        {
            return 1;
        }
        return 0;
    }
    int isFull()
    {
        if (r == size - 1)
        {
            return 1;
        }
        return 0;
    }
    void display()
    {
        if (isEmpty())
        {
                        cout<<"Queue is Empty"<<endl;

        }
        else{

        
            for (int i = f; i <= r; i++)
            {
                cout << "Element is : " << arr[i] << endl;
            }
        }

    }
    int enqueue(int x)
    {
        if (!isFull())
        {
            arr[++r] = x;

            if (f == -1)
            {
                f=0;
            }
            return 1;
        }

        cout<<"Queue is full"<<endl;
        return 0;
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            return arr[f++];
        }
        cout<<"Queue is Empty"<<endl;

        return -1;
    }

    int showfront()
    {
        if (!isEmpty())
        {
            // if (f==-1)
            // {
            //                return arr[f+1];

            // }
            return arr[f];
        }
        return -1;
    }
};
int main()
{
    Queue s(100); // created 100 int arr element Queue
    s.enqueue(11);
    s.enqueue(2);
    s.enqueue(3);
    s.enqueue(4);
    s.enqueue(5);

    cout<<"dequed ele "<<s.dequeue()<<endl;
    cout<<"dequed ele "<<s.dequeue()<<endl;
    cout<<"dequed ele "<<s.dequeue()<<endl;
    cout<<"dequed ele "<<s.dequeue()<<endl;
    // cout<<"dequed ele "<<s.dequeue()<<endl;
    // cout<<"dequed ele "<<s.dequeue()<<endl;
    // cout<<"dequed ele "<<s.dequeue()<<endl;

    cout<<s.f<<endl;
    cout<<s.r<<endl;
    // cout<<"dequed ele "<<s.dequeue()<<endl;

    s.display();
    cout << s.showfront();
    return 0;
}