
#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *root = new ListNode();
        ListNode *sum = getSum(l1, l2, root, 0);
        return sum;
    }

    ListNode *getSum(ListNode *l1, ListNode *l2, ListNode *root, int carry)
    {
        if (l1 == nullptr and l2 == nullptr)
        {
            if (carry == 0)
                return nullptr;
            else
            {
                ListNode *toRet = new ListNode(carry);
                return toRet;
            }
        }
        else if (l1 == nullptr)
        {
            root->val = (l2->val + carry) % 10;
            carry = floor((l2->val + carry) / 10);
            root->next = new ListNode(0, nullptr);
            root->next = getSum(nullptr, l2->next, root->next, carry);
            return root;
        }
        else if (l2 == nullptr)
        {
            root->val = (l1->val + carry) % 10;
            carry = floor((l1->val + carry) / 10);
            root->next = new ListNode(0, nullptr);
            root->next = getSum(nullptr, l1->next, root->next, carry);
            return root;
        }
        else
        {
            root->val = (l1->val + l2->val + carry) % 10;
            carry = floor((l1->val + l2->val + carry) / 10);
            root->next = new ListNode(0, nullptr);
            root->next = getSum(l2->next, l1->next, root->next, carry);
            return root;
        }
    }
};