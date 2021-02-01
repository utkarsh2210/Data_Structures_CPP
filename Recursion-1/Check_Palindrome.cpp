/*
Check if a given String S is palindrome or not (using recursion). Return true or false.
Input Format :
String S
Output Format :
true or false
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
*/

#include<cstring>

bool checkIt(char input[], int s, int e)
{
    if(s>e)
    {
        return true;
    }
    
    if(input[s]!=input[e])
    {
        return false;
    }
    
    return checkIt(input, s+1, e-1);
    
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int s=0; 
    int e=strlen(input);
    
    return checkIt(input, s, e-1);

}


#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}