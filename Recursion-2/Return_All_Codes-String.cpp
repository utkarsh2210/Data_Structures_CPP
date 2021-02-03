/* 
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.

Input format :
A numeric string


Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw

*/

#include <iostream>
#include "solution.h"
using namespace std;

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}


#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    
     
    //string alph[]={"","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
   
      if(input.empty())
    {
        output[0]="";
         return 1;
    }
    string temp1[1000];
    int k=0;
    int scodes=getCodes(input.substr(1),temp1);
    char ch=input[0]-'0' + 'a' -1;
    for(int i=0;i<scodes;i++){
        output[k]=ch + temp1[i];
        k++;
    }
    if(input.length() >=2){
        int f=input[0]-'0';
        int s=input[1]-'0';
        int cur=f*10+s;
        if(cur>=10 && cur<=26){
            string temp2[1000];
            char ch1=cur + 'a' - 1;
            int gcodes=getCodes(input.substr(2),temp2);
            for(int i=0;i<gcodes;i++){
                output[k]=ch1+temp2[i];
                k++;
            }
        }
    }
    return k;
}


