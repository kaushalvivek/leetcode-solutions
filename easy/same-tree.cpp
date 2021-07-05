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
    list <TreeNode*> tree1 = {nullptr}, tree2 = {nullptr};
    
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == nullptr and q == nullptr)
            return true;
        if (p == nullptr or q == nullptr)
            return false;
        
        if (p->val == q-> val) {
            tree1.emplace_front(p->left);
            tree1.emplace_front(p->right);
            tree2.emplace_front(q->left);
            tree2.emplace_front(q->right);
        }
        else
            return false;
        
        tree1.pop_back();
        tree2.pop_back();
        
        if (tree1.empty() and tree2.empty()) return true;
        if (tree1.empty() or tree2.empty()) return false;
        
        while(!tree1.empty() and !tree2.empty())
        {
            if (tree1.back() == nullptr and tree2.back() == nullptr)
            {
                tree1.pop_back();
                tree2.pop_back();
                continue;
            }
            
            if (isSameTree(tree1.back(), tree2.back()) == false) return false;
        }
        
        return true;
    }
};