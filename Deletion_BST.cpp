#include <iostream>

// Define the structure of a BST node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node with a given key from the BST
Node* deleteNode(Node* root, int key) {
    // Base case: If the tree is empty, return nullptr
    if (root == nullptr) {
        return root;
    }

    // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    // If the key to be deleted is larger than the root's key, then it lies in the right subtree
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    // If the key is the same as the root's key, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Create a sample BST
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    std::cout << "Inorder traversal before deletion: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Delete a node (e.g., delete 30)
    int keyToDelete = 30;
    root = deleteNode(root, keyToDelete);

    std::cout << "Inorder traversal after deletion of " << keyToDelete << ": ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
