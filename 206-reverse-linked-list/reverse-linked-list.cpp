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
    ListNode* reverseList(ListNode* head) {
        ListNode* Curr=head;
        ListNode* prev=NULL;
        while(Curr!=NULL){
        ListNode* Nex = Curr->next; // 3rd element list me
        Curr->next=prev; // 3rd ko pehli null wali jagah bhej dia
        prev=Curr; // null wali jagah ko beech me kar dia
        Curr=Nex; // beech wali ko 3rd position bhej dia
        }
          return prev;

    }

}; 