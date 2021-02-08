/*
Given a singly linked list of integers, sort it using 'Bubble Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.


Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1

Sample Output 1 :
 3 4 5 6 7 8 9 10 


Sample Input 2 :
2
-1
10 -5 9 90 5 67 1 89 -1

Sample Output 2 :
-5 1 5 9 10 67 89 90 

*/

//bubble sort iterative
#include <iostream>
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *bubbleSort(Node *head)
{
	// Write your code here
    Node *temp = head;
    Node *ansHead = head;
    int n=0;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    
    for(int i=0; i<n-1; i++)
    {
        Node *curr = ansHead;
        Node *prev = NULL;
        
        while(curr->next!=NULL)
        {
            if(curr->data >  curr->next->data)
            {
                Node *next = curr->next;
                
                if(prev==NULL)
                {
                    curr->next = next->next;
                    prev = next;
                    prev->next = curr;
                    ansHead = prev;
                }
                else
                {
                    curr->next = next->next;
                    next->next = curr;
                    prev->next = next;
                    prev=next;
                }
            }
            else
            {
                prev = curr;
                curr=curr->next;
            }
        }
    }
    
    return ansHead;
}

using namespace std;
#include "solution.h"
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}