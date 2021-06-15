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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if(root)que.push(root);
        while(!que.empty()){
            int size = que.size();
            int maxN = que.front()->val;
            while(size-->0){
                TreeNode* p = que.front();
                que.pop();
                if(p->val>maxN)maxN=p->val;
                if(p->left)que.push(p->left);
                if(p->right)que.push(p->right);
            }
            result.push_back(maxN);
        }
        return result;
    }
};