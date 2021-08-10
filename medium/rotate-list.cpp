#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == nullptr) { // if list empty
            return head;
        }
        
        ListNode* curr = head;
        int sizeOfList = 0;
        
        while(curr != nullptr) { // get size of List
            sizeOfList++;
            curr = curr->next;
        }
        
        k = k%sizeOfList; // don't rotate for full rotations
        
        while(k--) {
            curr = head;
            int last;
            int temp;
            
            while(curr->next != nullptr)  { // find last value
                curr = curr->next;
            }
            
            last = curr->val;
            curr = head;
            
            while (curr != nullptr) { // rotation
                temp = curr->val;
                curr->val = last;
                last = temp;
                curr = curr->next;
            }
        }
        return head;
    }
};