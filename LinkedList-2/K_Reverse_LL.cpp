/*

Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
 'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 4 -> 5

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case or query contains the elements of the singly linked list separated by a single space.
The second line of input contains a single integer depicting the value of 'k'.

Output format :
For each test case/query, print the elements of the updated singly linked list.
Output for every test case will be printed in a seperate line.


Sample Input 1 :
1
1 2 3 4 5 6 7 8 9 10 -1
4

Sample Output 1 :
4 3 2 1 8 7 6 5 10 9


Sample Input 2 :
2
1 2 3 4 5 -1
0
10 20 30 40 -1
4

Sample Output 2 :
1 2 3 4 5 
40 30 20 10 
*/

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

Node *reverse(Node *head)
{
    Node *next = head;
    Node *prev = NULL;
    Node *curr = head;
    
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
    }
    
    return prev;
}

Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(k==0)
    {
        return head;
    }
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    
    Node *temp = head;
    Node *head1 = head;
    Node *tail1 = head;
    int count = 0;
    
    while(count!=k-1 && tail1->next!=NULL)
    {
        count++;
        tail1 = tail1->next;
    }
    
    Node *head2 = tail1->next;
    tail1->next = NULL;
    
    Node *temp1 = reverse(head1);
    
    Node *temp2 = kReverse(head2, k);
    temp->next = temp2;
    return temp1;
    
    
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
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}