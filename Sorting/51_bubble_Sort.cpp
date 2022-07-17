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

void bubbleShort(int *A, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        // cout << "pass : " << i + 1 << endl;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
void bubbleShortAdaptive(int *A, int size)
{
    int temp, isSorted;
    for (int i = 0; i < size - 1; i++)
    {
        cout << "pass : " << i + 1 << endl;
        isSorted = 1;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
            return;
    }
}

int main()
{
    int size = 6;
    // int A[] = {9, 5, 2, 3};
    // int A[] = {1,2,4,3};
    int A[] = {3325, 23543, 5, 54545, 433, 6568};
    print(A, size);
    // bubbleShort(A, size);
    bubbleShortAdaptive(A, size);
    print(A, size);
    return 0;
}