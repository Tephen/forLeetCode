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
    void traversal(TreeNode* root,int& sum,bool isLeft) {
        if(!root->left && !root->right){//叶子结点
            if(isLeft) sum += root->val;//左叶子结点计算和，右叶子结点直接返回
            return;
        }
        if(root->left) traversal(root->left,sum,true);
        if(root->right) traversal(root->right,sum,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        traversal(root,sum,false);
        return sum;
    }
};