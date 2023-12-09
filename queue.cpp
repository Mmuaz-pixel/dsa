#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class queue
{
public:
    Node *first;
    Node *last;

    queue()
    {
        last = nullptr;
        first = nullptr;
    }

    void enque(int x)
    {
        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;

        if (isEmpty())
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }
    void deque()
    {
        if (!isEmpty())
        {
            Node *temp = first;
            first = first->next;
            delete temp;
        }
    }

    int peek()
    {
        if (!isEmpty())
        {
            return first->data;
        }
        return -1;
    }

    bool isEmpty()
    {
        return first == nullptr;
    }

    void traverse()
    {

        Node *current = first;

        std::cout << "Queue elements: ";
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};

int main()
{
    queue q1; 
    q1.enque(1); 
    q1.enque(2); 
    q1.enque(3); 
    q1.enque(4); 
    q1.enque(5);
    q1.deque(); 
    q1.deque(); 
    q1.enque(6); 
    q1.traverse();  
    return 0;
}