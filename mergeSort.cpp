#include <iostream>
using namespace std;

void merge(int A[], int low, int mid, int high);

void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

void merge(int A[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int B[high - low + 1]; // Corrected array size

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k - low] = A[i]; // Adjust the index
            k++;
            i++;
        }
        else
        {
            B[k - low] = A[j]; // Adjust the index
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        B[k - low] = A[i]; // Adjust the index
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k - low] = A[j]; // Adjust the index
        k++;
        j++;
    }

    for (int i = low; i <= high; i++) // Adjust the loop bounds
    {
        A[i] = B[i - low]; // Adjust the index
    }
}

int main()
{
    int arr[] = {25, 64, 12, 22, 11, 1, 3, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}