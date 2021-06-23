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
    int getHeight(TreeNode* root) {
        if(!root) return 0;
    //返回值-1表示子树已不为平衡数，一举两得
        if(getHeight(root->left)==-1 || getHeight(root->right)==-1)return -1;
        if(abs(getHeight(root->left)-getHeight(root->right))>1) return -1;
        return max(getHeight(root->left),getHeight(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root)==-1?false:true;
    }
};