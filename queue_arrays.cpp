#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void enque(int data) {
        if (!isFull()) {
            if (isEmpty())
                front = 0;
            arr[++rear] = data;
        }
        else {
            cout << "Queue is full. Cannot enqueue." << endl;
        }
    }

    int deque() {
        if (!isEmpty()) {
            int data = arr[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front++;
            }
            return data;
        }
        else {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // You can choose a different way to handle this case.
        }
    }

    ~Queue() {
        delete[] arr;
    }
};

int main()
{
    Queue Q1(3); 
    Q1.enque(1); 
    Q1.enque(2); 
    Q1.enque(3);

    cout << Q1.deque() << "\n";  
    Q1.enque(4);
    cout << Q1.deque() << " \n";  
    Q1.enque(5);
    cout << Q1.deque() << " \n";
    cout << Q1.deque() << " \n";
    cout << Q1.deque() << " \n";

    return 0;
}
