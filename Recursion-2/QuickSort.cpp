/*
Sort an array A using Quick Sort.
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

int partition(int a[], int si, int en)
{
    int count=0;
    int x=a[si];
    for(int i=si+1; i<=en; i++)
    {
        if(x>a[i])
        {
            count++;
        }
            
    }
    int pi=si+count;

        int temp=a[si];
        a[si]=a[si+count];
        a[si+count]=temp;

        int j=si,k=en;
        while(j<pi && k>pi)
        {
            if(a[j]<a[pi])
            {
                j++;
            }
            else if(a[k]>=a[pi])
            {
                k--;
            }
            else{
                    int tem=a[k];
                    a[k]=a[j];
                    a[j]=tem;
                }
                
        }
    return pi;
}

void quickSo(int arr[], int si, int en)
{
    if(si>=en)
    {
        return;
    }
    int p = partition(arr, si, en);
    quickSo(arr, si, p-1);
    quickSo(arr, p+1, en);
        
    
}

void quickSort(int input[], int size) {
    
    if(size==0 || size==1)
    {
        return;
    }

    quickSo(input, 0, size-1);
}


#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}