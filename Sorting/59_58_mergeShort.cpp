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

void mergeMidShortedArray(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high + 1];

    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        if (A[j] < A[i])
            B[k++] = A[j++];
    }

    while (i <= mid)
        B[k++] = A[i++];

    while (j <= high)
        B[k++] = A[j++];

    for (i= low; i <= high; i++)
        A[i] = B[i];
}

void mergeShort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (high + low) / 2;
        mergeShort(A, low, mid);
        mergeShort(A, mid + 1, high);
        mergeMidShortedArray(A, low, mid, high);
    }
};

int main()
{
    // int A[] = {9, 5, 2, 3, 4, 56, 3, 456, 34};
    // int A[] = {7, 8, 9, 12, 45, 1, 2, 5, 7, 89};
    int A[] = {6,7,8,9,10,1,2,4,7,34};

    int size = sizeof(A) / sizeof(int);

    // print(A, size);
    // mergeMidShortedArray(A,  0,4, size - 1);
    mergeShort(A, 0, size - 1);
    print(A, size);

    return 0;
}