#include <iostream>
#include <stack>
using namespace std;

string subtract(string num1, string num2)
{
    stack<int> num1st; 
    stack<int> num2st; 
    stack<int> result; 
    string result_; 

    for(int i = 0; i<num1.length(); i++)
    {
        num1st.push(num1[i]-'0'); 
    }
    for(int i = 0; i<num2.length(); i++)
    {
        num2st.push(num2[i]-'0'); 
    }

    int i = num1.length(); 
    int j = num2.length(); 

    while(i!=0 || j!=0)
    {
        int operator1 = i>0?num1[i-1]-'0':0; 
        int operator2 = j>0?num2[j-1]-'0':0; 

        if(operator1<operator2)
        {
            num1[i-2] = num1[i-2] - 1; 
            operator1 = 10 + operator1; 
        }

        result.push(operator1 - operator2); 
        i--; 
        j--; 
    }

    while(!result.empty())
    {
        result_ += to_string(result.top()); 
        result.pop(); 
    }

    return result_; 
}

int main()
{
    string num1 = "9090"; 
    string num2 = "1111"; 

    cout << subtract(num1, num2); 
    return 0;
}