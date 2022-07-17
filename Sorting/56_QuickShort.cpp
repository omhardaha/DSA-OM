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
int partition(int A[], int low, int high)
{

    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (pivot >= A[i])
        {
            i++;
        }
        while (pivot < A[j])
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
};

void QuickShort(int *A, int low, int high)
{
    if (low < high)
    {
        int partitionIndex;
        partitionIndex = partition(A, low, high);
        QuickShort(A, low, partitionIndex - 1);
        QuickShort(A, partitionIndex + 1, high);
    }
}

int main()
{
    int A[] = {9, 5, 2, 3, 4, 56, 3, 456, 34};

    int size = sizeof(A) / sizeof(int);
    print(A, size);
    QuickShort(A, 0, size - 1);
    print(A, size);
    return 0;
}