#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    list<pair<Node*, int>> to_visit;
    
    void BFS(Node* node, int level) {
        
        // if no other element on level
        if (to_visit.empty() or to_visit.back().second != level) {
            node->next = nullptr;
        }
        // if there is another element on level
        else {
            node->next = to_visit.back().first;
        }
        
        // add children to list
        if (node->left != nullptr) to_visit.push_front({node->left, level+1});
        if (node->right != nullptr) to_visit.push_front({node->right, level+1});
        
        while(!to_visit.empty()) {
            pair<Node*, int> curr = to_visit.back(); // store last element for BFS
            to_visit.pop_back(); // pop last element
            BFS(curr.first, curr.second);
        }
        
        return;
    }
    
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        BFS(root,1);    
        return root;
    }
};