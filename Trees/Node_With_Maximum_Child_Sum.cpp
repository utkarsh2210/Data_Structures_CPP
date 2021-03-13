/*

Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. 

Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.

Constraints:
Time Limit: 1 sec


Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1

*/

#include <iostream>
#include <queue>
#include <vector>
#include "solution.h"
#include<climits>

using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};



TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> q1;
    q1.push(root);
    TreeNode<int>* ans = root;
    int maxSum = INT_MIN;
    
    while(!q1.empty())
    {
        int currSum = 0;
        TreeNode<int>* front = q1.front();
        q1.pop();
        
        for(int i=0; i<front->children.size(); i++)
        {
            q1.push(front->children[i]);
            currSum+=front->children[i]->data;
        }
        currSum+= front->data;
        
        if(currSum > maxSum)
        {
            maxSum = currSum;
            ans = front;
        }
    }
    
    return ans;
    
}


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}