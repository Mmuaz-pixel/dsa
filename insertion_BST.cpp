#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// recursive
// struct node *insertion(node *root, int value)
// {
//     if (root == NULL)
//     {
//         struct node *newNode = new node;
//         newNode->data = value;
//         newNode->left = newNode->right = NULL;
//         return newNode;
//     }

//     if (value < root->data)
//     {
//         root->left = insertion(root->left, value);
//     }
//     else if (value > root->data)
//     {
//         root->right = insertion(root->right, value);
//     }

//     return root;
// }

// iterative
struct node *insertion(node *root, int value)
{
    struct node *newNode = new node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;

    if (root == NULL)
    {
        return newNode;
    }

    struct node *current = root;
    struct node *parent = NULL;

    while (current)
    {
        parent = current;
        if (value < current->data)
        {
            current = current->left;
        }
        else if (value > current->data)
        {
            current = current->right;
        }
        else
        {
            delete newNode;
            return root;
        }
    }

    if (value < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }

    return root;
}

// left -> root -> right
void inOrderTraversal(node *ptr)
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
    p->data = 10;
    p->left = NULL;
    p->right = NULL;

    insertion(p, 5);
    insertion(p, 11);
    insertion(p, 1);
    insertion(p, 3);
    insertion(p, 21);
    insertion(p, 18);
    insertion(p, 17);
    insertion(p, 19);
    inOrderTraversal(p);
    return 0;
}