#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front, rear, capacity, size;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = item;
        size++;

        cout << "Enqueued: " << item << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            // If the queue becomes empty after dequeue
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element.\n";
            return -1;
        }

        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty. No rear element.\n";
            return -1;
        }

        return arr[rear];
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);

    cout << "Front: " << cq.getFront() << endl;
    cout << "Rear: " << cq.getRear() << endl;

    cq.dequeue();
    cq.dequeue();

    cq.enqueue(5);
    cq.enqueue(6);

    cout << "Front: " << cq.getFront() << endl;
    cout << "Rear: " << cq.getRear() << endl;

    return 0;
}
