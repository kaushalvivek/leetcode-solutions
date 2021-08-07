/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int DFS(TreeNode* root, int depth) {
        if (root == nullptr)
            return depth;
        return max(DFS(root->left, depth+1), DFS(root->right, depth+1));
    }
    
    int diameterForNode(TreeNode* root) {
        int rDepth = DFS(root->right, 0);
        int lDepth = DFS(root->left, 0);
        return rDepth + lDepth;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        ans = max(diameterForNode(root), ans);
        
        if (root->left != nullptr) diameterOfBinaryTree(root->left);
        if (root->right != nullptr) diameterOfBinaryTree(root->right);
        
        return ans;
    }
};