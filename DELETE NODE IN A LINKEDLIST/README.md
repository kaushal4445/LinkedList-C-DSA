🗑️ Delete Node in a Linked List






📌 Problem Statement

You are given a node in a singly linked list (NOT the head).
Your task is to delete that node from the linked list.

⚠️ You are NOT given access to the head of the list.

🧠 Intuition

Normally, to delete a node:

You need access to the previous node

Then you update:

prev->next = current->next

❌ But here, we don’t have the previous node

💡 Approach (Your Method)

👉 Instead of deleting directly, we:

Copy the value of the next node into the current node
Move forward in the list
Repeat until we reach the last node
Remove the last node
🔄 Step-by-Step Example
Initial List:
4 → 5 → 1 → 9
      ↑ (node to delete)
After shifting values:
4 → 1 → 9 → 9
After deleting last node:
4 → 1 → 9
⚙️ Implementation
class Solution {
public:
    void deleteNode(ListNode* node) {
       ListNode* previous = NULL;

       while(node != NULL && node->next != NULL){
           node->val = node->next->val;  // Copy next node value
           previous = node;              // Track previous node
           node = node->next;            // Move forward
       }

       previous->next = NULL;            // Remove last node
       delete(node);                     // Delete last node
    }
};
⏱️ Complexity Analysis
Type	Complexity
Time Complexity	O(n)
Space Complexity	O(1)
⚖️ Pros & Cons
✅ Pros
Easy to understand
Works correctly for the problem
❌ Cons
Not optimal (takes O(n) time)
Extra traversal of the list
Better O(1) solution exists
🚀 Optimal Approach (Recommended)

Instead of shifting all values, we can:

👉 Copy next node value and delete next node directly

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};
⚡ Optimal Complexity
Type	Complexity
Time Complexity	O(1)
Space Complexity	O(1)
