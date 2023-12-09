
#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
private:
    struct tree_node
    {
        tree_node *left;
        tree_node *right;
        int data;
    };

public:
    tree_node *root;

    BinarySearchTree()
    {
        root = nullptr;
    }
    bool isEmpty() const { return root == NULL; }
    void print_inorder();
    void inorder(tree_node *);
    void print_preorder();
    void preorder(tree_node *);
    void print_postorder();
    void postorder(tree_node *);
    void insert(int);

    tree_node *remove(int d, tree_node *node)
    {
        if (node == nullptr)
            return nullptr;
        // First locate the element, if the element is not found, simply generate an error message
        //  Then there will be three cases in removing d. Code accordingly
        //  1. Removing a leaf node
        //  2. Removing a node with a single child
        //  3. Removing a node with 2 children, then adjust its parents and grand children links

        else if (d < node->data)
        {
            // recursion
            node->left = remove(d, node->left);
            return node;
        }

        else if (d > node->data)
        {
            // recursion
            node->right = remove(d, node->right);
            return node;
        }

        else if (d == node->data)
        {
            // 1. leaf node
            if (node->left == NULL && node->right == NULL)
            {
                node = NULL;
            }

            // 2.Single child
            else if (node->left == NULL && node->right != NULL)
            {
                tree_node *temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == NULL && node->left != NULL)
            {
                // if one node is null make the other side equal to that root node
                tree_node *temp = node;
                node = node->left;
                delete temp;
            }

            // 3. 2 children
            else
            {
                tree_node *successor = node;
                successor = successor->right;
                while (successor->left)
                {
                    successor = successor->left;
                } // finding the leftmost in the right of node to be deleted

                node->data = successor->data;                  // making node data equal to that of leftmost in right
                node->right = remove(node->data, node->right); // finally deleting that leftmost node
            }
        }
        return node;
    }
};
void BinarySearchTree::insert(int d)
{
    struct tree_node *newNode = new tree_node; // making a new node to insert
    newNode->data = d;
    newNode->left = newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        struct tree_node *current = root;
        struct tree_node *parent = NULL;

        while (current)
        {
            parent = current; // keeping track of current node and its parent
            if (d < current->data)
            {
                current = current->left;
            }
            else if (d > current->data)
            {
                current = current->right;
            }
            else
            {
                delete newNode;
            }
        }

        // inserting node according to data value
        if (d < parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }
}

void BinarySearchTree::print_inorder()
{
    inorder(root);
    cout << endl;
}

void BinarySearchTree::inorder(tree_node *p)
{
    if (p != nullptr)
    {
        // inorder traversal of tree
        inorder(p->left);
        cout << p->data << "\t";
        inorder(p->right);
    }
}

void BinarySearchTree::print_preorder()
{
    preorder(root);
    cout << endl;
}

void BinarySearchTree::preorder(tree_node *p)
{
    if (p)
    {
        // preorder traversal of tree
        cout << p->data << "\t";
        preorder(p->left);
        preorder(p->right);
    }
}

void BinarySearchTree::print_postorder()
{
    postorder(root);
    cout << endl;
}

void BinarySearchTree::postorder(tree_node *p)
{
    if (p)
    {
        // postorder traversal of tree
        postorder(p->left);
        postorder(p->right);
        cout << p->data << "\t";
    }
}

void insertIntoTree(BinarySearchTree *b)
{
    cout << "How many elements do you want to insert?" << endl;
    int n;
    cin >> n;
    int val;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element # " << i << ":"
             << "\t";
        cin >> val;
        b->insert(val);
    }
}

int main()
{
    BinarySearchTree b;

    while (true)
    {

        int menuOption = 0;

        while (menuOption > 6 || menuOption < 1) // This loop can exit program
        {
            cout << "\t*****************************************" << endl;
            cout << "\t* Select Option:\t\t\t*" << endl;
            cout << "\t*\t1. Insert New Data\t\t*" << endl;
            cout << "\t*\t2. In-Order Traversal\t\t*" << endl;
            cout << "\t*\t3. Pre-Order Traversal\t\t*" << endl;
            cout << "\t*\t4. Post-Order Traversal\t\t*" << endl;
            cout << "\t*\t5. Delete an item\t\t*" << endl;
            cout << "\t*\t6. Exit\t\t\t\t*" << endl;
            cout << "\t*****************************************" << endl;

            cout << "> ";
            cin >> menuOption;

            if (menuOption == 6)
            {
                return 0; // Exiting
            }

            switch (menuOption)
            {
            case 1:
            {
                insertIntoTree(&b);
                break;
            }
            case 2:
            {
                b.print_inorder();
                break;
            }
            case 3:
            {
                b.print_preorder();
                break;
            }
            case 4:
            {
                b.print_postorder();
                break;
            }
            case 5:
            {
                cout << "Enter element to remove:" << endl;
                int elem;
                cin >> elem;
                b.remove(elem, b.root);
            }
            }
        }
    }
    getchar();
}
