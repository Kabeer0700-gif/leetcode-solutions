/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* DummyNode = new ListNode(0);
        DummyNode->next = head;
        ListNode* temp = head;
        ListNode* prev = DummyNode;

        while(temp != nullptr){
            if(temp->val == val){
                prev->next = temp->next;
                ListNode* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }else{
                prev = temp;
                temp = temp->next;
            }
        }

        ListNode* newHead = DummyNode->next;
        delete DummyNode;
        return newHead;
    }
};
