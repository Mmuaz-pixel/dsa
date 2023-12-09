#include <iostream>
using namespace std;

struct node{
    int value; 
    struct node * nextNode; 
}; 

void listTraversal(struct node *ptr)
{
    while (ptr)
    {
        cout << ptr->value << " ";
        ptr = ptr->nextNode; 
    } 
}

struct node * insertAtFirst (struct node *head, int data)
{   
    struct node *ptr = new node; 
    ptr->value = data; 
    ptr->nextNode = head; 
    return ptr; 
}

struct node * insertAtIndex (struct node *head, int data, int index)
{
    struct node*ptr = new node; 
    struct node *temp = head; 
    for(int i = 0; i<index-1; i++)
    {
        temp = temp->nextNode; 
    }
    ptr->value = data; 
    ptr->nextNode = temp->nextNode;  
    temp->nextNode = ptr;
    return head; 
}

void insertAtEnd (struct node *head, int data)
{
    struct node * ptr = new node; 
    struct node * temp = new node; 

    while(temp->nextNode)
    {
        temp = temp->nextNode; 
    }

    ptr->value = data; 
    temp->nextNode = ptr; 
    ptr->nextNode = NULL; 
}

void insertAfterNode (struct node *prevNode, int data)
{
    struct node * ptr = new node; 
    ptr->nextNode = prevNode->nextNode; 
    prevNode->nextNode = ptr; 
    ptr->value = data; 
}

struct node * deleteAtFirst(struct node * head)
{
    struct node * ptr = head->nextNode;
    delete head; 
    return ptr;  
}

struct node * deleteAtIndex(struct node * head, int index)
{
    struct node *ptr = head; 
    for(int i = 0; i<index-1; i++)
    {   
        ptr = ptr->nextNode; 
    }
    struct node *previous= new node;


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

    head = insertAtFirst(head, 2); // correct  
    head = insertAtIndex(head, 100, 2); // correct 
    head = deleteAtFirst(head); // working correctly
    listTraversal(head); 
    return 0;
}