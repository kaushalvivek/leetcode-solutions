#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    
    int sum = 0;
    bool found = false;
    
    bool isLeaf(TreeNode* node) {
        return (node->left == nullptr and node->right == nullptr);
    }
    
    void DFS(TreeNode* node, int target) {
        if (found) return;
        
        sum+= node->val;
        
        if (isLeaf(node) and sum==target) found = true;
        
        if (node->left != nullptr) DFS(node->left, target);
        if (node->right != nullptr) DFS(node->right, target);
        
        sum -= node->val;
        return;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {        
        if (root == nullptr) return false; // empty tree
        if (isLeaf(root)) return (root->val == targetSum); // single node
        DFS(root, targetSum);
        return found;
    }
};