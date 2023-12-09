#include <iostream>
using namespace std;

void countSort(int A[], int max, int len)
{
    int B[max+1] = {0}; 
    int C[len]; 
    for(int i = 0; i<len; i++)
    {
        B[A[i]]++; 
    }
    int temp = 0; 
    for(int i = 0; i<max+1; i++)
    {
        while(B[i])
        { 
            C[temp] = i; 
            temp++; 
            B[i]--; 
        } 
    }

    for(int i = 0; i<len; i++)
    {
        A[i] = C[i]; 
    }
}

int main()
{
    int arr[] = {25, 64, 12, 22, 11, 1, 3, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    countSort(arr, max, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}