#include<iostream>
#include<bits/stdc++.h>

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
    
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr and right == nullptr) return true;
        if (left == nullptr or right == nullptr) return false;
        
        if (left->val != right->val) return false;
        
        if ((isMirror(left->left, right->right) and isMirror(left->right, right->left)) == false) return false;
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
};