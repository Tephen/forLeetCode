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
        //原地反转
        ListNode *pre,*cur;
        cur = head;
        pre = nullptr;
        while(cur){
            ListNode *curNext = cur->next;
            cur->next = pre; 
            pre = cur;
            cur = curNext;
        }
        return pre;//cur==nullptr,pre指向原链表最后一个节点
    }
};