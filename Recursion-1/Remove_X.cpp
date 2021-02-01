/*

Given a string, compute recursively a new string where all 'x' chars have been removed.

Input format :
String S

Output format :
Modified String


Sample Input 1 :
xaxb

Sample Output 1:
ab


Sample Input 2 :
abc

Sample Output 2:
abc
*/

// Change in the given string itself. So no need to return or print anything
#include <iostream>
#include "solution.h"
using namespace std;


void removeX(char input[]) {
    // Write your code here
    if(input[0]=='\0')
    {
        return;
    }
    
    if(input[0]=='x')
    {
        for(int i=0; input[i]!='\0'; i++)
        {
            input[i] = input[i+1];
        }
        removeX(input);
    }
        
    removeX(input+1);

}



int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
