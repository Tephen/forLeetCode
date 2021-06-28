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
    void searchBST(TreeNode* cur,int val){
        if(val<cur->val){
            if(!cur->left){
                cur->left = new TreeNode(val);
                return;
            }
            else return searchBST(cur->left,val);
        }
        else{//保证新值不在原树中故可不考虑=
            if(!cur->right){
                cur->right = new TreeNode(val);
                return;
            }
            else return searchBST(cur->right,val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root = new TreeNode(val);
            return root;
        }
        else{
            searchBST(root,val);
            return root;
        }
    }
};