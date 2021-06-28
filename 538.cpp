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
private:
    vector<TreeNode*> midOrder;
    void traversal(TreeNode* root){
        if(!root)return;
        traversal(root->left);
        midOrder.push_back(root);
        traversal(root->right);
        return;
    }
public://得到中序指针列表后可方便操作
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        int addNum=0;
        for(int i = midOrder.size()-1;i>=0;i--){
            midOrder[i]->val += addNum;
            addNum = midOrder[i]->val;
        }
        return root;
    }
};