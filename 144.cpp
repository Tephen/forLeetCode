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
    void traversal(TreeNode* cur,vector<int>& nums){
        if(cur==nullptr)return;
        nums.push_back(cur->val);
        traversal(cur->left,nums);
        traversal(cur->right,nums);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root,result);
        return result;
    }
};

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root != nullptr){
            stack<TreeNode*> st;
            st.push(root);
            while(!st.empty()){
                TreeNode* cur = st.top();
                result.push_back(cur->val);
                st.pop();
                if(cur->right!=nullptr){
                    st.push(cur->right);
                }
                if(cur->left!=nullptr){
                    st.push(cur->left);
                }
            }
        }
        return result;
    }
};