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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> que;
        if(root) que.push(root);
        while(!que.empty()){
            int size = que.size();
            int i = size;
            long sum = 0;
            while(i-->0){
                TreeNode* p = que.front();
                que.pop();
                sum+=p->val;
                if(p->left)que.push(p->left);
                if(p->right)que.push(p->right);
            }
            result.push_back(sum/double(size));
        }
        return result;
    }
};