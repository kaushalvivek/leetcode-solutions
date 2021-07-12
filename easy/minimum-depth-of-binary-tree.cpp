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
    int curr_depth, min_depth;
    
    bool isLeaf(TreeNode* node) {
        return (node->left == nullptr and node->right == nullptr);
    }
    
    void DFS(TreeNode* node) {
        
        curr_depth++;
        if (curr_depth >= min_depth) return;
        
        if (isLeaf(node)) min_depth = curr_depth;
        
        if (node->left != nullptr) {
            DFS(node->left);
            curr_depth--;
        }
        
        if (node->right != nullptr) {
            DFS(node->right);
            curr_depth--;
        }
        
        return;
    }
    
    int minDepth(TreeNode* root) {
        
        int right_min = INT_MAX, left_min = INT_MAX;
        
        if (root == nullptr) return 0;
        
        curr_depth = 1;
        min_depth = INT_MAX;
        
        if (root->right !=nullptr) {
            DFS(root->right);
            right_min = min_depth;
        }
        
        curr_depth = 1;
        min_depth = INT_MAX;
        
        if (root->left !=nullptr) {
            DFS(root->left);
            left_min = min_depth;
        }
        
        if (isLeaf(root)) return 1;
        
        return min(left_min, right_min);
    }
};