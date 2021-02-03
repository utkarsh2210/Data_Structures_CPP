/* 

Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print the subsets in different lines.

Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)


Sample Input:
3
15 20 12

Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 

*/

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}

void printSubsets(int input[], int m, int out[], int n)
{
    if(m==0)
    {
        for(int i=0; i<n; i++)
        {
            cout<<out[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    printSubsets(input+1, m-1, out, n);
    out[n] = input[0];
    out[n+1]='\0';
    printSubsets(input+1, m-1, out, n+1);
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int out[1000];
    printSubsets(input, size, out, 0);
}
