#include <iostream>
using namespace std;

void insertionSort(int *A, int length)
{
    for(int i = 1; i<length; i++)
    {
        int key = A[i]; 
        int j = i-1; 

        while(A[j]>key && j>=0)
        {
            A[j+1] = A[j]; 
            j--; 
        }

        A[j+1] = key; 
    }
}
 
int main()
{
    int array[] = {19,2,11,89,94,14,1}; 
    insertionSort(array, sizeof(array)/sizeof(array[0])); 
    for(int i = 0; i<7; i++)
    {
        cout << array[i] << " "; 
    }
    return 0;
}