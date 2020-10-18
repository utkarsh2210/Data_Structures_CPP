/*
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 1000
Sample Input:
6 
2 6 8 5 4 3
Sample Output:
2 3 4 5 6 8
*/

void mergeIt(int input[], int si, int e)
{
    int size = e-si+1;
    int *arr = new int[size];
    int mid = (si+e)/2;
    int k=0;
    
    int i=si;
    int j=mid+1;
    
    while(i<=mid && j<=e)
    {
        if(input[i]<input[j])
        {
            arr[k] = input[i];
            i++;
        }
        else
        {
            arr[k] = input[j];
            j++;
        }
        
        k++;
    }
    while(i<=mid)
    {
        arr[k++]=input[i++];
    }
     while(j<=e)
    {
        arr[k++]=input[j++];
    }
    
    int n=0;
    for(int m=si; m<=e; m++)
    {
        input[m]=arr[n];
        n++;
    }
    
    delete [] arr;
}

void mergeSort2(int input[], int si, int e)
{
    if(si>=e)
    {
        return;
    }
    
    int mid = (si+e)/2;
    
    mergeSort2(input, si, mid);
    mergeSort2(input, mid+1, e);
    mergeIt(input, si, e);
}

void mergeSort(int input[], int size){
	// Write your code here
    mergeSort2(input, 0, size-1);
        
}


#include <iostream>
#include "solution.h"
using namespace std;

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}