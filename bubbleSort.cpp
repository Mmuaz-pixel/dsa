#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int array[] = {100, 1, 19, 10, 12, 14, 18};
    int size = sizeof(array) / sizeof(array[0]);
    int *ptr = array;
    bubbleSort(ptr, size);

    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }
    return 0;
}
