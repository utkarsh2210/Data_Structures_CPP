/*

Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains data of the node with second largest data.

Constraints:
Time Limit: 1 sec


Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40

*/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include "solution.h"

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


TreeNode<int>* returnMax(TreeNode<int>* root)
{
    TreeNode<int>* ans = root;

    
    for(int i=0; i<root->children.size(); i++)
    {
        TreeNode<int>* maxNode = returnMax(root->children[i]);
        if(maxNode->data > ans->data)
        {
            ans = maxNode;
        }
    }
    return ans;
}

TreeNode<int>* secondMax(TreeNode<int>* root, TreeNode<int>* maxNode)
{
    TreeNode<int>* ans = root;
    
    for(int i=0; i<root->children.size(); i++)
    {
        TreeNode<int>* secondMaxNode = secondMax(root->children[i], maxNode);
        if(secondMaxNode->data > ans->data && secondMaxNode->data < maxNode->data)
        {
            ans = secondMaxNode;
        }
    }
    return ans;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL)
    {
        return NULL;
    }
    TreeNode<int>* maxNode = returnMax(root);
    return secondMax(root, maxNode);
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

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}