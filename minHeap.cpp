#include <iostream>
#include <math.h>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

class Heap
{
public:
    int values[30];
    int size;

public:
    Heap()
    {
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == 30;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Heap is empty!\n";
            return -1;
        }
        else
        {
            return values[1]; // The minimum element is at the root
        }
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Heap is full!\n";
            return;
        }

        size++;
        values[size] = value; // Add the new element at the end

        int current = size;

        // Fix the heap property by swapping with parents if needed
        while (current > 1 && values[current] < values[current / 2])
        {
            swap(values[current], values[current / 2]);
            current /= 2;
        }
    }

    void heapify(int index)
    {
        int left = 2 * index;
        int right = 2 * index + 1;
        int smallest = index;

        // Find the smallest among the node and its children
        if (left <= size && values[left] < values[smallest])
        {
            smallest = left;
        }

        if (right <= size && values[right] < values[smallest])
        {
            smallest = right;
        }

        // If the smallest is not the current node, swap and recursively heapify
        if (smallest != index)
        {
            swap(values[index], values[smallest]);
            heapify(smallest);
        }
    }

    void buildheap()
    {
        for (int i = size / 2; i >= 1; i--)
        {
            heapify(i);
        }
    }

    void buildheapfromarray(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
            push(arr[i]);
        buildheap();
    }

    void deleteMin()
    {
        if (isEmpty())
        {
            cout << "Heap is empty!\n";
            return;
        }

        // Replace the root with the last element
        values[1] = values[size];
        size--;

        // Heapify the root
        heapify(1);
    }

    int pop(int index)
    {
        if (index < 1 || index > size)
        {
            cout << "Invalid index!\n";
            return -1;
        }
        else
        {
            int poppedValue = values[index];
            values[index] = values[size];
            size--;

            // Fix the heap property if necessary
            heapify(index);

            return poppedValue;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Heap is empty!\n";
            return;
        }
        for (int i = 1; i <= size; i++)
        {
            cout << values[i] << " ";
            if (i == 1 || i == 3 || i == 7 || i == 15)
                cout << endl;
        }
        cout << endl;
    }

    int getSize()
    {
        return size;
    }

    int getHeight()
    {
        return static_cast<int>(log2(size)) + 1;
    }
};

int main()
{
    Heap myHeap = Heap();
    const int arraySize = 15;
    int array[arraySize];

    // Initialize array with random values
    for (int i = 0; i < arraySize; i++)
        array[i] = (rand() % 100) + 1;

    // Build heap from the array
    myHeap.buildheapfromarray(array, arraySize);

    int choice;
    do
    {
        cout << "\nMin Heap Menu:\n";
        cout << "1. Print Heap\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Minimum\n";
        cout << "4. Pop Element at Index\n";
        cout << "5. Get Size\n";
        cout << "6. Get Height\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Heap elements: ";
            myHeap.print();
            break;

        case 2:
            int newValue;
            cout << "Enter the value to insert: ";
            cin >> newValue;
            myHeap.push(newValue);
            cout << "Value inserted.\n";
            break;

        case 3:
            myHeap.deleteMin();
            cout << "Minimum element deleted.\n";
            break;

        case 4:
            int indexToDelete;
            cout << "Enter the index to pop: ";
            cin >> indexToDelete;
            myHeap.pop(indexToDelete);
            cout << "Element at index " << indexToDelete << " popped.\n";
            break;

        case 5:
            cout << "Heap size: " << myHeap.getSize() << endl;
            break;

        case 6:
            cout << "Heap height: " << myHeap.getHeight() << endl;
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}
