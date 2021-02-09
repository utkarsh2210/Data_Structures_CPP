/*
For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.

Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.

Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.

Sample Input 1:
{{{
Sample Output 1:
-1

Sample Input 2:
{{{{}}
Sample Output 2:
1

*/

#include <iostream>
#include<stack>
#include <string>
using namespace std;

#include "solution.h"


int countBracketReversals(string input) {
	// Write your code here
    int i=0;
    stack<char> s1;
    int len =0;
    
   for(int j=0; input[j]!='\0'; j++)
   {
       len++;
   }
    if(len%2!=0)
    {
        return -1;
    }
    
    while(input[i]!='\0')
    {
        if(input[i]=='{')
        {
            s1.push('{');
        }
        else if(input[i]=='}')
        {
            if(!s1.empty())
            {
                char a = s1.top();
                if(a=='{')
                {
                    s1.pop();
                }
                else if(a=='}')
                {
                    s1.push('}');
                }
            }
            else
            {
                s1.push('}');
            }
        }
        i++;
    }
    
    int count=0;
    while(!s1.empty())
    {
        char c1 = s1.top();
        s1.pop();
        char c2 = s1.top();
        s1.pop();
        
        if(c1==c2)
        {
            count++;
        }
        else
        {
            count+=2;
        }
    }
    
    return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}