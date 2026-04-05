class Solution {
public:
    void deleteNode(ListNode* node) {
       ListNode* previous = NULL;
       while(node != NULL && node->next != NULL){
        node->val = node->next->val;  // Copy next node value
        previous = node; // Skip the next node
        node = node->next;
       }
       previous->next = NULL;
       delete(node);
    }
};
