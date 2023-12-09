#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;

    int getHeight()
    {
        if (!this)
            return 0;
        else
            return this->height;
    }
    int getBalanceFactor()
    {
        if (!this)
            return 0;
        return this->left->getHeight() - this->right->getHeight();
    }
};

Node *createNode(int value)
{
    struct Node *ptr = new Node;
    ptr->data = value;
    ptr->height = 0;
    ptr->left = NULL;
    ptr->right = NULL;
}

struct Node *rightRotate(Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(y->left->getHeight(), y->right->getHeight());
    x->height = max(x->left->getHeight(), x->right->getHeight());
    return x;
}

struct Node *leftRotate(Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    y->height = max(y->left->getHeight(), y->right->getHeight());
    x->height = max(x->left->getHeight(), x->right->getHeight());
    return y;
}

struct Node *insertion(Node *root, int value)
{
    if (root == NULL)
    {
        struct Node *newNode = new Node;
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (value < root->data)
    {
        root->left = insertion(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertion(root->right, value);
    }

    root->height = 1 + max(root->left->getHeight(), root->right->getHeight());
    int balance_factor = root->getBalanceFactor();

    // left left case (rotate right once)

    if (balance_factor > 1 && value < root->left->data)
    {
        rightRotate(root);
    }

    // right right case (rotate left once)

    if (balance_factor < -1 && value > root->right->data)
    {
        leftRotate(root);
    }

    // left right case - insetion is first left and then right (first rotate left then right)

    if (balance_factor > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        rightRotate(root);
    }

    // right left case - insertion is in first right and then left (first rotate right then left)

    if (balance_factor < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        leftRotate(root);
    }

    return root;
}

int main()
{
    //       5 
    //      / \ 
    //     4   1
    //    /     \ 
    //           12
    //             \ 
    //              15
    return 0;
}