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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow,*fast;
        slow = fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){//相遇点
                ListNode *p,*q;
                p = head;
                q = fast;
                while(p!=q){
                    p = p->next;
                    q = q->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};