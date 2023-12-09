#include <iostream>
using namespace std;

struct Array
{
    int total_size; 
    int used_size; 
    int *ptr; 
}; 

void createArray(struct Array* a, int tsize, int usize)
{
    (*a).total_size = tsize; 
    (*a).used_size = usize; 
    (*a).ptr = new int[tsize]; 
}

void show(struct Array *a)
{
    for(int i = 0; i<a->used_size; i++)
    {
        cout << (a->ptr)[i] << " "; 
    }
}

void setValue(struct Array *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        cin >> (a->ptr)[i]; 
    }
}

void delet(struct Array *a, int index)
{
    for(int i = index; i<a->used_size; i++)
    {
        (a->ptr)[i] = (a->ptr)[i+1]; 
    }
    a->used_size --; 
}

int main()
{
    struct Array marks;
    createArray(&marks, 10, 5); 
    setValue(&marks); 
    delet(&marks, 3); 
    show(&marks); 
}
