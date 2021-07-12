#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isLeaf(TreeNode* node){
        return (node->left == nullptr and node->right == nullptr);
    }
    
    void DFS(TreeNode* node, vector<vector<int>> &ans, vector<int> &curr, int target, int sum) {
        curr.push_back(node->val);
        sum+= node->val;
        
        if (isLeaf(node) and target == sum) ans.push_back(curr);
        
        if (node->left != nullptr) DFS(node->left, ans, curr, target, sum);
        if (node->right != nullptr) DFS(node->right, ans, curr, target, sum);
        
        curr.pop_back();
        sum-=node->val;
        return;
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        int sum = 0;
        
        if (root != nullptr) DFS(root, ans, curr, targetSum, sum);
        return ans;
    }
};