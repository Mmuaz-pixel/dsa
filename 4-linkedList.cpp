#include <iostream>
using namespace std;

// draw backs
// 1) extra memory used (one for value and one for pointer to next node)

struct node
{
    int value;
    struct node *nextNode;
};

void listTraversal(struct node *ptr)
{
    while (ptr)
    {
        cout << ptr->value << " ";
        ptr = ptr->nextNode; 
    } 
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    head = new node;
    second = new node;
    third = new node;

    head->value = 7;
    head->nextNode = second;
    second->value = 8;
    second->nextNode = third;
    third->value = 9;
    third->nextNode = NULL;

    listTraversal(head); 
    return 0;
}