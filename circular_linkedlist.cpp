#include <iostream>
using namespace std;

struct node{
    int value; 
    struct node * nextNode; 
}; 

void circularLinkedListTraversal(struct node * head)
{
    struct node * temp = new node;
    temp = head; 

    while(true)
    {
        cout << temp->value << " "; 
        temp = temp->nextNode; 
        if(temp == head)
        {
            break; 
        }
    } 
}

struct node * insertAtFirst(struct node * head)
{
    struct node * ptr = new node; 
    struct node * p = head->nextNode; 

    // todo
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
    third->nextNode = head; 

    circularLinkedListTraversal(head);  
    return 0;
}