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






void countShort(int A[], int size)
{
    int j = 0;
    int max = A[0];

///finding max element
    for (int i = 0; i < size; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }


// intialising max size Array
    int B[max + 1];

// intialising all elemnt with 0
    for (int i = 0; i < max + 1; i++)
    {
        B[i] = 0;
    }

// increment B[j] when j = A[i] 
    for (int i = 0; i < size; i++)
    {
        B[A[i]]++;
    }

// if B[i] is greater than 0 then A[j] = i;
    for (int i = 0; i < max + 1; i++)
    {
        while (B[i] != 0)
        {
            A[j++] = i;
            B[i]--;
        }
    }
}

int main()
{
    int A[] = {9, 5,5656,546,4456, 2, 3, 4, 56, 3, 30, 34};

    int size = sizeof(A) / sizeof(int);

    print(A, size);

    countShort(A, size);
    print(A, size);
    return 0;
}