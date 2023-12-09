#include <iostream>
using namespace std;

int binarySearch(int arr[],int size,  int element)
{
    int low, mid, high;

    low = 0; 
    high = size - 1; 
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; 
}
int main()
{
    int i[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(i)/sizeof(i[0]); 
    cout << binarySearch(i,size, 3); 
    return 0;
}