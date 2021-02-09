/*
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.
Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.
You need to return a boolean value indicating whether the expression is balanced or not.


Input Format:
The first and the only line of input contains a string expression without any spaces in between.

Output Format:
The only line of output prints 'true' or 'false'.


Sample Input 1 :
(()()())

Sample Output 1 :
true


Sample Input 2 :
()()(()

Sample Output 2 :
false

*/

#include<stack>

bool isBalanced(string expression) 
{
    // Write your code here
    if(expression[0]=='\0')
    {
        return true;
    }
    stack<char> s1;
    int i=0;
    
    while(expression[i]!='\0')
    {
        if(expression[i]=='(')
        {
            s1.push('(');
        }
        else if(expression[i]==')')
        {
            if(!s1.empty())
            {
                if(s1.top() == '(')
            	{
                	s1.pop();
            	}
            }
            else
            {
                return false;
            } 
        }
        i++;
    }
    
    if(s1.empty())
    {
        return true;
    }
    
    return false;
    
}

#include <iostream>
#include <string>
using namespace std;

#include "solution.h"

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}