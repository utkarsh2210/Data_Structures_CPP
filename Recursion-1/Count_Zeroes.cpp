/*
Given an integer n, count and return the number of zeros that are present in the given integer using recursion.
Input Format :
Integer n
Output Format :
No. of 0s
Sample Input :
10204
Sample Output
2
*/



int countZeros(int n) {
    // Write your code here
    if(n<=9 && n!=0)
    {
        return 0;
    }
    
    if(n==0)
    {
        return 1;
    }
    
    int ans = countZeros(n/10);
    if(n%10==0)
    {
        return ans+1;
    }
    else
    {
        return ans;
    }

}


#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}