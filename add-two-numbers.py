# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        root = ListNode()
        return self.smartSum(root, l1, l2, 0)
    
    def smartSum(self, root, curr1, curr2, carry):
        if curr1 == None and curr2 == None:
            if carry:
                return ListNode(carry, None)
            else:
                return None
        elif curr1 == None:
            root.val = (curr2.val + carry)%10
            carry = (curr2.val + carry)//10
            root.next = ListNode()
            root.next = self.smartSum(root.next, None, curr2.next, carry)
            return root
        elif curr2 == None:
            root.val = (curr1.val + carry)%10
            carry = (curr1.val + carry)//10
            root.next = ListNode()
            root.next = self.smartSum(root.next, None, curr1.next, carry)
            return root
        else:
            root.val = (curr1.val + curr2.val + carry)%10
            carry = (curr1.val + curr2.val + carry)//10
            root.next = ListNode()
            root.next = self.smartSum(root.next, curr1.next, curr2.next, carry)
            return root
        