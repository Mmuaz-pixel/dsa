#include <iostream>

using namespace std;

class CircularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int maxSize;

public:
    CircularQueue(int size)
    {
        maxSize = size;
        arr = new int[maxSize];
        front = -1;
        rear = -1;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return (rear + 1) % maxSize == front;
    }

    void enqueue(int item)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxSize;
        }
        arr[rear] = item;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a sentinel value indicating failure.
        }                                                                               
        else if (front == rear)
        {
            int item = arr[front];
            front = rear = -1;
            return item;
        }
        else
        {
            int item = arr[front];
            front = (front + 1) % maxSize;
            return item;
        }
    }
};

int main()
{
    CircularQueue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    cout << "Dequeue: " << queue.dequeue() << endl;
    queue.enqueue(6);
    cout << "Dequeue: " << queue.dequeue() << endl;
    return 0;
}
