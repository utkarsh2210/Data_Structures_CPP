/*
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

Input format :
Numeric string S (string, Eg. "1234")


Output format :
Corresponding integer N (int, Eg. 1234)


Sample Input 1 :
00001231

Sample Output 1 :
1231


Sample Input 2 :
12567

Sample Output 2 :
12567

*/

#include<cstring>
#include <iostream>
#include "solution.h"
using namespace std;

int convertIt(char input[], int size)
{
    if(size==-1)
    {
        return 0;
    }
    
    int a = input[size] - 48;
    int ans = convertIt(input, size-1);
    ans = ans*10 + a;
}

int stringToNumber(char input[]) {
    // Write your code here
    int len = strlen(input);
    return convertIt(input, len-1);

}


int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
