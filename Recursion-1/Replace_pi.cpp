/*
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Sample Input 1 :
xpix

Sample Output :
x3.14x


Sample Input 2 :
pipi

Sample Output :
3.143.14
*/

// Change in the given string itself. So no need to return or print anything
#include<cstring>
#include <iostream>
#include "solution.h"
using namespace std;


void replacePi(char input[]) {
	// Write your code here
    if(input[0]=='\0')
    {
        return;
    }
    
    if(input[0]=='p' && input[1]=='i')
    {
       int n = strlen(input);
        for(int i=n; i>=2; i--)
        {
            input[i+1] = input[i-1];
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }
    
    replacePi(input+1);

}


int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
