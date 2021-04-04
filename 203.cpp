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
        ListNode *fakeHead =new ListNode(0,head);
        ListNode *curNode = fakeHead;
        while(curNode->next != nullptr){
            if(curNode->next->val==val){
                ListNode *temp = curNode->next;
                curNode->next = curNode->next->next;
                delete temp;
            }
            else curNode = curNode->next;
        }
        return fakeHead->next;
    }
};