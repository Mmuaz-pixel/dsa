#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *arr;

    int pop()
    {
        if (top > 1)
        {
            return arr[--top];
        }
        else{
            throw "Stack is empty";
        }
    }

    void push(int value)
    {
        if (top < size)
        {
            arr[top++] = value;
        }
        else {
            throw "Stack is full"; 
        }
    }
};

int main()
{
    struct Stack *s = new Stack;
    s->size = 80;
    s->top = 0;
    s->arr = new int[s->size]; 
    return 0;
}