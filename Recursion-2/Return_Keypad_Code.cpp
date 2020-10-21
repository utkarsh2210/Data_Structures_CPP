/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : The order of strings are not important.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/


#include <string>
using namespace std;

int keypad(int num, string output[]){
    
    if(num==0)
    {
        output[0]="";
        return 1;
    }
 
    string alph[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    int a = num/10;
    int b = num%10;
    string small[1000];
    
    int c = keypad(a, small);
    string d = alph[b];
    int k=0;
    for(int i=0; i<d.size(); i++)
    {
        for(int j=0; j<c; j++)
        {
        	output[k]=small[j]+d[i];
            k++;
        }
    }
    return k;
    
    
}


#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
