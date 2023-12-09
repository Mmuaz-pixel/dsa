#include <iostream>
#include <limits.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// left -> root -> right
int inOrderTraversal(node *ptr, int &prev)
{
    if (ptr)
    {
        if (inOrderTraversal(ptr->left, prev) == -1)
            return -1;

        if (ptr->data <= prev)
            return -1;

        prev = ptr->data;

        if (inOrderTraversal(ptr->right, prev) == -1)
            return -1;
    }

    return 0;
}

int main()
{
    struct node *p = new node;
    struct node *p1 = new node;
    struct node *p2 = new node;
    struct node *p3 = new node;
    struct node *p4 = new node;
    p->data = 10;
    p->left = p1;
    p->right = p2;

    //       10
    //     /   \
    //    5     15
    //   / \
    //  1   8

    p1->data = 5;
    p1->left = p3;
    p1->right = p4;

    p2->data = 15;
    p2->left = NULL;
    p2->right = NULL;

    p3->data = 1;
    p3->left = NULL;
    p3->right = NULL;
    p4->data = 8;
    p4->left = NULL;
    p4->right = NULL;

    int prev = INT_MIN;
    cout << "Results: ";
    cout << ((inOrderTraversal(p, prev)==-1)?"Not a binary search tree":"Binary search tree");
    return 0;
}
