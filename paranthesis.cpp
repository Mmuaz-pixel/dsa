#include <iostream>
// #include <string>

using namespace std; 
// Define a Node structure for the linked list
struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top; // Pointer to the top of the stack

public:
    Stack()
    {
        top = nullptr; // Initialize the stack with an empty list
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(int value)
    {
        // Create a new node
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = top; // Set the new node's next pointer to the current top
        top = newNode;       // Update the top pointer to the new node
    }

    // Function to pop an element from the stack
    int pop()
    {
        if (isEmpty())
        {
            return -1; // Return a sentinel value to indicate an error
        }
        int value = top->data;
        Node *temp = top; // Store the current top node in a temporary variable
        top = top->next;  // Move the top pointer to the next node
        delete temp;      // Delete the old top node
        return value;
    }

    // Function to peek at the top element without removing it
    int peek()
    {
        if (isEmpty())
        {
            std::cerr << "Stack is empty. Cannot peek." << std::endl;
            return -1; // Return a sentinel value to indicate an error
        }
        return top->data;
    }

    // Function to display the elements of the stack
    void display()
    {
        Node *current = top;
        std::cout << "Stack: ";
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory when the stack is destroyed
    ~Stack()
    {
        while (!isEmpty())
        {
            pop(); // Pop all elements and delete the nodes
        }
    }
};

int isParanthesisBalanced(string exp)
{
    Stack *smallBracket = new Stack; 
    Stack *mediumBracket = new Stack; 
    Stack *largeBracket = new Stack; 
    for(int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
        {
            smallBracket->push(1); 
        }
        else if(exp[i]==')')
        {
            int result = smallBracket->pop(); 
            if(result == -1)
            {
                return 0; 
            }
        }
        if(exp[i]=='{')
        {
            mediumBracket->push(1); 
        }
        else if(exp[i]=='}')
        {
            int result = mediumBracket->pop(); 
            if(result == -1)
            {
                return 0; 
            }
        }
        if(exp[i]=='[')
        {
            largeBracket->push(1); 
        }
        else if(exp[i]==']')
        {
            int result = largeBracket->pop(); 
            if(result == -1)
            {
                return 0; 
            }
        }
    }

    return (smallBracket->isEmpty() && mediumBracket->isEmpty() && largeBracket->isEmpty());
}

int main()
{
    string exp = "[9+(32-1){12-1]0}*(3)"; 
    cout << (isParanthesisBalanced(exp)?"'Expression is balanced for paranthesis'": "'Expression is not balanced for parethesis'"); 
    return 0;
}
