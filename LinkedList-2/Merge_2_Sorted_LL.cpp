/*
You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the first sorted singly linked list separated by a single space. 

The second line of the input contains the elements of the second sorted singly linked list separated by a single space. 


Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element


Output :
For each test case/query, print the resulting sorted singly linked list, separated by a single space.

Output for every test case will be printed in a seperate line.


Sample Input 1 :
1
2 5 8 12 -1
3 6 9 -1

Sample Output 1 :
2 3 5 6 8 9 12 


Sample Input 2 :
2
2 5 8 12 -1
3 6 9 -1
10 40 60 60 80 -1
10 20 30 40 50 60 90 100 -1

Sample Output 2 :
2 3 5 6 8 9 12 
10 10 20 30 40 40 50 60 60 60 80 90 100

*/

#include <iostream>
using namespace std;
#include "solution.h"


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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if(head1==NULL)
    {
        if(head2==NULL)
        {
            return head1;
        }
        return head2;
    }
    
    if(head2==NULL)
    {
        if(head1==NULL)
        {
            return head2;
        }
        return head1;
    }
    

    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *newNode = NULL;
    Node *newNodeHead = new Node(NULL);
    
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data <= temp2->data)
        {
            if(newNode==NULL)
            {
                newNode = temp1;
                newNodeHead = newNode;
            }
            else
            {
                Node *newN = new Node(temp1->data);
                newNode->next = newN;
                newNode = newN;
            }
        
            temp1 = temp1->next;
        }
        else
        {
            if(newNode==NULL)
            {
                newNode = temp2;
            	newNodeHead = newNode;
            }
            else
            {
                Node *newN = new Node(temp2->data);
                newNode->next = newN;
                newNode = newN;
            }
            
            temp2 = temp2->next;
        }
    }
    
    if(temp1==NULL)
    {
        newNode->next = temp2;
    }
    else if (temp2==NULL)
    {

        newNode->next = temp1;

    }
    
    return newNodeHead;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}