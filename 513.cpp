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
    int findBottomLeftValue(TreeNode* root) {//层序遍历
        queue<TreeNode*> que;
        que.push(root);
        int result;
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* p = que.front();
                if(i==0 && !p->left && !p->right)result = p->val;
                que.pop();
                if(p->left)que.push(p->left);
                if(p->right)que.push(p->right);
            }
        }
        return result;
    }
};