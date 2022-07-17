#include <iostream>
using namespace std;

void print(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void insertionShort(int *A, int size)
{
    int key, j;
    for (int i = 1; i <= size - 1; i++)
    {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
            // cout<<"swap"<<endl;
        }
        A[j + 1] = key;
    }
}
void BubbleShort(int *A, int size)
{int temp;
    for (int i = 0; i < size - 1; i++)
    {
        cout << "df" << endl;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (A[j + 1] < A[j])
            {
             temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // int A[] = {9, 5, 2, 3, 4};
    int A[] = {9, 45, 2, 3, 4, 575, 453, 34, 4};
    int size = sizeof(A) / sizeof(int);
    print(A, size);
    insertionShort(A, size);
    BubbleShort(A, size);
    print(A, size);
    return 0;
}