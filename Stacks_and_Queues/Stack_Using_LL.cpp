/*
You need to implement a Stack class using linked list.
The data members should be private.
Implement the following public functions :
1. Constructor -
Initialises the data member (i.e. head to null).
2. push :
This function should take one argument of type T and has return type void. This function should insert an element in the stack. Time complexity should be O(1).
3. pop :
This function takes no input arguments and has return type T. This should removes the last element which is entered and return that element as an answer. Time complexity should be O(1).
4. top :
This function takes no input arguments and has return type T. This should return the last element which is entered and return that element as an answer. Time complexity should be O(1).
5. size :
Return the size of stack i.e. count of elements which are present ins stack right now. Time complexity should be O(1).
6. isEmpty :
Checks if the stack is empty or not. Return true or false
*/

#include<iostream>
using namespace std;


template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack
    
    public :
    
    Stack() {
        head = NULL;
        size=0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size==0;
        
    }
    
    void push(T element) {
      Node<T> *newNode = new Node<T>(element);
        if(head==NULL)
        {
            head = newNode;
        }
      else
      {
          newNode->next = head;
          head = newNode;
      }
		size++;
        
    }
    
    T pop() {
       
        if(size==0)
        {
            return 0;
        }
        else
        {
            size--;
            T ans = head->data;
            
            head = head->next;
            return ans;
        }
        
        
    }
    
    T top() {
        if(size==0)
        {
            return 0;
        }
        else
        {
            return head->data;
        }
        
    }
    
  
    
};

//Test Code
int main() {
        
        Stack<int> st;
        
        int choice;
        cin >> choice;
        int input;
        
        while (choice !=-1) {
            if(choice == 1) {
                cin >> input;
                st.push(input);
            }
            else if(choice == 2) {
                int ans = st.pop();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 3) {
                int ans = st.top();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 4) {
                cout << st.getSize() << endl;
            }
            else if(choice == 5) {
		if(st.isEmpty()){
                	cout << "true" << endl;
		}else{
			cout << "false" << endl;
		}
            }
            cin >> choice;
        }
}