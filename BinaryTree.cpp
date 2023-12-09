#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int main()
{
    struct node *p = new node;
    struct node *p1 = new node;
    struct node *p2 = new node;
    p->data = 10;
    p->left = p1;
    p->right = p2; 

    p1->data = 20;
    p1->left = NULL;
    p1->right = NULL;

    p2->data = 30;
    p2->left = NULL;
    p2->right = NULL;

    // binary tree traversal
    return 0;
}