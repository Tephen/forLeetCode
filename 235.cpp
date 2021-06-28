/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* searchBST(TreeNode* cur,TreeNode* p,TreeNode* q){
        if(cur->val<=q->val && cur->val>=p->val) return cur;
        else if(cur->val<p->val)return searchBST(cur->right,p,q);
        else return searchBST(cur->left,p,q);
    }
public://当cur->val位于[p->val,q->val]之间时即为最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp;
        if(p->val>q->val){
            temp = p;
            p = q;
            q = temp;
        }
        return searchBST(root,p,q);
    }
};