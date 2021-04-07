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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0,head);//使用虚拟头简化操作很多
        ListNode *slow,*fast;
        slow = fast = dummyHead;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        while(fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *q = slow->next;
        slow->next = slow->next->next;
        delete q;
        return dummyHead->next;
    }
};