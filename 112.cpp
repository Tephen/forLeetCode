/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        if(!root->left && !root->right){
            if(root->val==targetSum)return true;
            else return false;
        }
        if(root->left){
            if(hasPathSum(root->left,targetSum-root->val)) return true;//快速向上回溯
        }
        if(root->right){
            if(hasPathSum(root->right,targetSum-root->val)) return true;
        }
        return false;
    }
};