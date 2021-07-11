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
    int curr_depth, max_depth;
    
    void checkDepth(TreeNode* root) {
        
        curr_depth+=1;
        max_depth = max(curr_depth, max_depth);
        
        if (root->left != nullptr)
        {
            checkDepth(root->left);
            curr_depth--;
        }
        
        
        if (root->right != nullptr)
        {
            checkDepth(root->right);
            curr_depth--;
        }
            
        return;
    }
    
    bool isBalanced(TreeNode* root) {
        
        // if tree is empty
        if (root == nullptr) return true;
        
        curr_depth = 0;
        max_depth = 0;
        
        if (root->left != nullptr) checkDepth(root->left);
        int curr_left = max_depth;
        
        curr_depth = 0;
        max_depth = 0;
        
        if (root->right != nullptr) checkDepth(root->right);
        int curr_right = max_depth;
        
        // if node is not balanced
        if (abs(curr_left - curr_right) > 1 ) return false;
        
        // check children
        return (isBalanced(root->left) and isBalanced(root->right));
    }
};