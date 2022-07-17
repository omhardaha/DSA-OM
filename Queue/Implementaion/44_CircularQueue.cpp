#include <iostream>
using namespace std;

class circularQueue
{
public:
    int f;
    int r;
    int size;
    int *arr;
    
    circularQueue(int x)
    {
        size = x+1;
        f = 0;
        r = 0;
        arr = new int[x];
    }

    int isEmpty()
    {
        if ((f == r) || f == -1)
        {
            return 1;
        }
        return 0;
    }

    int isFull()
    {
        if ((r + 1) % size == f)
        {
            return 1;
        }
        return 0;
    }
    // void display()
    // {
    //     if (isEmpty())
    //     {
    //         cout << "Queue is Empty" << endl;
    //     }
    //     else
    //     {

    //         for (int i = f; i <= r; i++)
    //         {
    //             cout << "Element is : " << arr[i] << endl;
    //         }
    //     }
    // }
    int enqueue(int x)
    {
        if (!isFull())
        {
            r = (r + 1) % size;
            arr[r] = x;

            // if (f == -1)
            // {
            //     f = 0;
            // }
        cout << "enQueued : " <<x<< endl;
            
            return 1;
        }

        cout << "Queue is full" << endl;
        return 0;
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            f = (f + 1) % size;

            return arr[f];
        }
        cout << "Queue is Empty" << endl;

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
    circularQueue s(4); // created 4 int arr element CQueue
    s.enqueue(11);
    s.enqueue(2);
    s.enqueue(3);
    s.enqueue(3);
    s.enqueue(3);
    // s.enqueue(4);
    // s.enqueue(64);
    // s.enqueue(634);
    // s.enqueue(5);

    // cout << "dequed ele " << s.dequeue() << endl;
    // cout << "dequed ele " << s.dequeue() << endl;
    // cout << "dequed ele " << s.dequeue() << endl;
    // cout << "dequed ele " << s.dequeue() << endl;
    cout<<"dequed ele "<<s.dequeue()<<endl;
    s.enqueue(43);
    // cout<<"dequed ele "<<s.dequeue()<<endl;
    // cout<<"dequed ele "<<s.dequeue()<<endl;

    // cout << s.f << endl;
    // cout << s.r << endl;
    // cout<<"dequed ele "<<s.dequeue()<<endl;

    // s.display();
    // cout << s.showfront();
    return 0;
}