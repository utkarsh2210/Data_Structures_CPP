/*
For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.


Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The first and the only line of output will print either 'true' or 'false'(without the quotes) denoting whether the input expression contains redundant brackets or not.

Sample Input 1:
a+(b)+c 
Sample Output 1:
true

Sample Input 2:
(a+b)
Sample Output 2:
false

*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

#include "solution.h"

bool checkRedundantBrackets(string expression) {
	// Write your code here
    stack<char> s1;
    stack<int> s2;
    int i=0;
    int opCount = 0;
    
    while(expression[i]!='\0')
    {
        if(expression[i]=='(')
        {
            if(opCount>0)
            {
                s2.push(opCount);
                opCount=0;
            }
            s1.push('(');
        }
        
        else if(expression[i]=='+' || expression[i]=='-' || expression[i]=='/' || expression[i]=='*')
        {
            if(!s1.empty())
            {
                opCount++; 
            }
        }
        
        else if(expression[i]==')')
        {
            if(!s1.empty())
            {
                if(opCount>0)
                {
                    opCount=0;
                    s1.pop();
                }
                else if(!s2.empty())
                {
                    s2.pop();
                    s1.pop();
                }
                else
                {
                    return true;
                } 
            }
            else
            {
                return true;
            }
        }
        i++;
        
    }
    
    return false;
    
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}