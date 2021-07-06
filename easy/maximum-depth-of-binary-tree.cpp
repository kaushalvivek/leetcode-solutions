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
    
    void DFS(TreeNode* node, int &curr, int &highest) {
        if (node == nullptr)
        {
            curr--;
            return;
        }
        
        highest = max(++curr, highest); // update depth
        
        if (node->left != nullptr) DFS(node->left, curr, highest);
        if (node->right != nullptr) DFS(node->right, curr, highest);
        
        curr--;
        return;
    }
    
    int maxDepth(TreeNode* root) {
        int curr = 0, highest = 0;
        DFS(root, curr, highest);
        return highest;
    }
};