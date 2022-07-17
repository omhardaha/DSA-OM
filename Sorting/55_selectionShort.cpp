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

void selectionShort(int *A, int size)
{
    int indexOfMin,temp;
    for (int i = 0; i < size - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
         temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main()
{
    int A[] = {9, 5, 2, 3, 4};
    // 2 5 9 3 4
    // 2 3 9 5 4
    // 2 3 4 5 9
    // int A[] = {9, 45, 2, 3, 4, 575, 453, 34, 4};
    int size = sizeof(A) / sizeof(int);
    print(A, size);
    selectionShort(A, size);
    print(A, size);
    return 0;
}