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
    void traversal(TreeNode* root,int targetSum,vector<int>& path,vector<vector<int>>& result){
        if(!root) return;
        path.push_back(root->val);
        if(!root->left && !root->right){
            if(targetSum==root->val) result.push_back(path);
            path.pop_back();
            return;
        }
        if(root->left) traversal(root->left,targetSum-root->val,path,result);
        // path.pop_back();
        if(root->right) traversal(root->right,targetSum-root->val,path,result);
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        traversal(root,targetSum,path,result);
        return result;
    }
};