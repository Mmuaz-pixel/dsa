#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// recursive
// bool search(node *ptr, int value)
// {
//     if(ptr)
//     {
//         if(ptr->data == value)
//         {
//             return 1;
//         }
//         else if(value > ptr->data)
//         {
//             return search(ptr->right, value);
//         }
//         else if(value < ptr->data)
//         {
//             return search(ptr->left, value);
//         }
//     }

//     return 0;
// }

// iterative 
bool search(node *root, int value)
{
    while (root)
    {
        if (root->data == value)
        {
            return true; 
        }
        else if (value > root->data)
        {
            root = root->right; 
        }
        else
        {
            root = root->left; 
        }
    }
    return false; // Value not found
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

    cout << search(p, 8);
    return 0;
}