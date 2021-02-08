/*
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.


Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'M,' and 'N,' respectively. A single space will separate them.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.


Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
2 2

Sample Output 1 :
1 2 5 6


Sample Input 2 :
2
10 20 30 40 50 60 -1
0 1
1 2 3 4 5 6 7 8 -1
2 3

Sample Output 2 :
1 2 6 7

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

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    if(head==NULL)
    {
        return head;
    }
    
    if(M==0)
    {
        return NULL;
    }
    int i=0, j=0;
    Node *temp = head;
    Node *currHead = head;
    Node *currTail = head;
    
    while(temp!=NULL)
    {
        if(i==M-1)
        {
            currTail = temp;
            while(j!=N && temp->next!=NULL)
            {
                j++;
                temp = temp->next;
            }
            
            currTail->next = temp->next;
            temp=temp->next;
            i=0;
            j=0;
        }
        else
        {
            i++;
            temp = temp->next;
        }
    }
    
    return currHead;
    
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}