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

void merge(int *A, int *B, int *C, int m, int n)
{
    int i, j, k;
    i = j = k = 0;
    while (i < m && j < n)
    {
        if (A[i] <= B[j])
            C[k++] = A[i++];
        if (B[j] < A[i])
            C[k++] = B[j++];
    }
    while (i < m)
    {
        C[k++] = A[i++];
    }
    while (j < n)
    {
        C[k++] = B[j++];
    }
}
void mergeInSameArray(int *D, int low, int mid, int high)
{
    int i, j, k;
    i = 0;
    j = mid + 1;
    k = 0;
    int C[high + 1];
    while (i <= mid && j <= high)
    {
        if (D[i] <= D[j])
            C[k++] = D[i++];
        if (D[j] < D[i])
            C[k++] = D[j++];
    }
    while (i <= mid)
    {
        C[k++] = D[i++];
    }
    while (j <= high)
    {
        C[k++] = D[j++];
    }

    for (int i = 0; i < high + 1; i++)
    {
        D[i] = C[i];
    }
};
void mergeShort(int *D, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeShort(D, low, mid);
        mergeShort(D, mid + 1, high);
        mergeInSameArray(D, low, mid, high);
    }
}
int main()
{
    // int A[] = {2, 2, 3, 6, 9, 67, 334};
    // int B[] = {1, 3, 6, 10, 11, 30, 100, 555};

    int D[] = {1, 3, 6, 4, 10, 1, 2, 7, 100, 3};

    // int size1 = sizeof(A) / sizeof(int);
    // int size2 = sizeof(B) / sizeof(int);
    int sizeD = sizeof(D) / sizeof(int);

    // int C[size1 + size2];

    // merge(A, B, C, size1, size2);
    // print(C, size1 + size2);

    // mergeInSameArray(D, 0, 3, 8);

    mergeShort(D, 0, sizeD - 1);
    print(D, 9);

    return 0;
}