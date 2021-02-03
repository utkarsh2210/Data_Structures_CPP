/*
Write a function that moves last element to front in a given singly Linked List.
For example, if the given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.
You just need to return the head of new linked list, don't print the elements.
Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Output format :
Updated list elements (separated by space)
Constraints :
1 <= n <= 10^4
Sample Input :
 1 2 3 4 5 6 -1
Note : -1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. Size of given linked list is 6.
Sample Output :
 6 1 2 3 4 5
*/


#include<iostream>
using namespace std;

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


Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if(head==NULL)
    {
        return head;
    }
    Node *temp = head;
    int count=0;
    
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    
    if(n>count)
    {
        return head;
    }
    temp = head;
    int x=0;
    
    while(x<count-n-1)
    {
        temp = temp->next;
        x++;
    }
    
    Node *temp2 = temp;
    while(temp2->next!=NULL)
    {
        temp2 = temp2->next;
    }
    
    temp2->next = head;
    head = temp->next;
    temp->next = NULL;
    
    return head;
}

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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}