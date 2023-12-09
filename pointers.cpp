#include <iostream>
using namespace std;

int main()
{
    int num1 = 10;
    int num2 = 15;
    int * const p = &num1; 
    // p = &num2; 
    cout << *p;

    const int * p2 = &num2;
    p2 = &num1;
    num1 = 30;
    cout << *p2;
    return 0;
}