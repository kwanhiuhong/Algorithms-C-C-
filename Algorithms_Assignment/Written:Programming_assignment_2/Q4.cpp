#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> global_array_for_storing_value;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    //here is to visit the root, but what I do is to put the value into a vector.
    global_array_for_storing_value.push_back(root->val);
    inorder(root->right);
}

int kthSmallest(TreeNode *root, int k){
    //I will first search through the whole trees using in-order search sequence
    inorder(root);
    //then sort the global array
    sort(global_array_for_storing_value.begin(), global_array_for_storing_value.end());
    return global_array_for_storing_value[k-1];
}





