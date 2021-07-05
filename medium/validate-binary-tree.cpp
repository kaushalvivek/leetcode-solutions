
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
    
    // all nodes on left less than root val
    bool leftIsCool(int val, TreeNode* node) {
        if (node == nullptr) return true;
        if (val <= node->val) return false;
        if ((leftIsCool(val, node->left) and leftIsCool(val, node->right)) == false) return false;
        return true;
    }
    
    // all nodes on right greater than root val
    bool rightIsCool(int val, TreeNode* node) {
        if (node == nullptr) return true;
        
        if (val >= node->val) return false;
        if ((rightIsCool(val, node->left) and rightIsCool(val, node->right)) == false) return false;
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        
        if (root == nullptr)
            return true;
        
        if (leftIsCool(root->val, root->left) == false) return false;
        if(isValidBST(root->left) == false) return false;

        if (rightIsCool(root->val, root->right) == false) return false;
        if(isValidBST(root->right) == false) return false;

        return true;
    }
};