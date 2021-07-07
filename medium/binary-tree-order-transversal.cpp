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

class Solution
{
public:
    list<pair<TreeNode *, int>> nodes; // nodes for BFS with level

    void BFS(TreeNode *root, vector<vector<int>> &ans, int level)
    {
        if (root == nullptr)
        {
            nodes.pop_back();
            return;
        }
        if (level > ans.size()) // add new level, when needed
        {
            ans.push_back({});
        }
        ans[level - 1].push_back(root->val);

        nodes.pop_back();

        if (root->right != nullptr)
            nodes.push_back({root->right, level + 1});
        if (root->left != nullptr)
            nodes.push_back({root->left, level + 1});

        while (!nodes.empty())
        {
            BFS(nodes.back().first, ans, nodes.back().second);
        }
        return;
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        nodes.push_back({root, 1});
        BFS(root, ans, 1);
        return ans;
    }
};