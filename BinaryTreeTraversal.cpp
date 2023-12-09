#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// imagine post, pre and in defines the positions of root

// root -> left -> right
void preOrderTraversal(node *ptr)
{
    if (ptr)
    {
        cout << ptr->data << " ";
        preOrderTraversal(ptr->left);
        preOrderTraversal(ptr->right);
    }
}

// left -> right -> root
void postOrderTraversal(node *ptr)
{
    if (ptr)
    {
        postOrderTraversal(ptr->left);
        postOrderTraversal(ptr->right);
        cout << ptr->data << " ";
    }
}

// left -> root -> right
void inOrderTraversal(node * ptr)
{
    if (ptr)
    {
        inOrderTraversal(ptr->left);
        cout << ptr->data << " ";
        inOrderTraversal(ptr->right);
    }
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

    p1->data = 20;
    p1->left = p3;
    p1->right = p4;

    p2->data = 30;
    p2->left = NULL;
    p2->right = NULL;

    p3->data = 40;
    p3->left = NULL;
    p3->right = NULL;
    p4->data = 50;
    p4->left = NULL;
    p4->right = NULL;
    // binary tree traversal

    cout << "\nPre order traversal: ";
    preOrderTraversal(p);
    cout << "\nPost order traversal: ";
    postOrderTraversal(p);
    cout << "\nIn order traversal: ";
    inOrderTraversal(p);
    return 0;
}