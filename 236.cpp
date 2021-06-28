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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        TreeNode* isInLeft = lowestCommonAncestor(root->left,p,q);
        TreeNode* isInRight = lowestCommonAncestor(root->right,p,q);
        if(!isInLeft && !isInRight) return nullptr;
        if(!isInLeft)return isInRight;
        if(!isInRight)return isInLeft;
        return root;
    }
};