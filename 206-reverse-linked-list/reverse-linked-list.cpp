class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;

        while (curr != nullptr) {
            forward = curr->next;     // store next node
            curr->next = prev;        // reverse link
            prev = curr;              // move prev forward
            curr = forward;           // move curr forward
        }
        return prev;                  // new head of reversed list
    }
};
