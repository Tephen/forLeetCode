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

//递归//
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root)return 0;
//         return max(maxDepth(root->left),maxDepth(root->right))+1;
//     }
// };

//迭代-层序遍历//
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth=0;
        queue<TreeNode*> que;
        if(root)que.push(root);
        while(!que.empty()){
            int size = que.size();
            while(size-->0){
                TreeNode* p = que.front();
                que.pop();
                if(p->left)que.push(p->left);
                if(p->right)que.push(p->right);
            }
            depth++;
        }
        return depth;
    }
};