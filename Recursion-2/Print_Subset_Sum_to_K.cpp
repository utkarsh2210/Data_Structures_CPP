/*

Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print them in different lines.

Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 


Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6

Sample Output:
3 3
5 1

*/

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}



void printSum(int input[], int m, int out[], int n, int k)
{
    if(m==0)
    {
        if(k==0)
        {
            for(int i=0; i<n; i++)
            {
                cout<<out[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    out[n] = input[0];
    out[n+1] = '\0';
    printSum(input+1, m-1, out, n+1, k-input[0]);
    printSum(input+1, m-1, out, n, k);
    
    
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int out[1000];
    printSum(input, size, out, 0, k);
}
