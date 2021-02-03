/*
Check if a given linked list is palindrome or not. Return true or false.
Indexing starts from 0.
Input format : Linked list elements (separated by space and terminated by -1)`
Sample Input 1 :
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
0 2 3 2 5 -1
Sample Output 2 :
false
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node* reverse(Node *head)
{
    Node *cur = head;
    Node *prev = NULL;
    Node *next = NULL;
    
    while(cur!=NULL)
    {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
    }
    
    return prev;
    
}   
    
bool isPalindrome(Node *head)
{
    //Write your code here
    if(head==NULL)
    {
        return true;
    }
    

    Node *temp = head;
    int count=0;
    while(temp!=NULL)
    {
    	count++;
        temp = temp->next;
    }
    
    int mid = count/2;
    int i=0;
    temp = head;
    while(i<mid-1)
    {
        i++;
        temp = temp->next;
    }
   
    Node *temp2 = reverse(temp->next);
    temp = head;
    while(temp!=NULL && temp2!=NULL)
    {
        if(temp->data!=temp2->data)
        {
            return false;
        }
        temp=temp->next;
        temp2=temp2->next;
    }
   
    return true;
    
    
}

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}