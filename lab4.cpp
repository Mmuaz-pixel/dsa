#include <iostream>
using namespace std;

class Stack {
private:
    int capacity;
    int top;
    char* data;

public:
    Stack(int size) {
        capacity = size;
        top = -1;
        data = new char[capacity];
    }

    void push(char element) {
        if (top == capacity - 1) {
            cout << "Stack is full. Cannot push." << endl;
        } else {
            data[++top] = element;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack is empty. Cannot pop." << endl;
            return '\0'; // Return null character for an empty stack.
        } else {
            return data[top--];
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull(){
        return top == capacity-1; 
    }

    void clear() {
        top = -1; // Reset the top to empty the stack.
    }

    char peek() {
        if (top == -1) {
            cout << "Stack is empty. Cannot peek." << endl;
            return '\0'; // Return null character for an empty stack.
        } else {
            return data[top];
        }
    }

    ~Stack() {
        delete[] data;
    }
};

bool areBracketsBalanced(string expr) {
    Stack s(expr.length());
    for (int i = 0; i < expr.length(); i++) {
        char bracket = expr[i];
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            s.push(bracket);
        } else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (s.isEmpty()) {
                return false;
            } else {
                char top = s.pop();
                if ((bracket == ')' && top != '(') || (bracket == ']' && top != '[') || (bracket == '}' && top != '{')) {
                    return false;
                }
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (areBracketsBalanced(expression)) {
        cout << "This expression is correct." << endl;
    } else {
        cout << "This expression is NOT correct." << endl;
    }

    return 0;
}
