/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        ListNode* current = node;

        current->val = next->val;
        current->next = next->next;
        next->next = NULL;
        delete next;

    }
};
