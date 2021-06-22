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
//     //比较左右子树是否镜像对称
//     bool compareLR(TreeNode* lc,TreeNode*rc){
//         //处理存在空树情况
//         if(lc&&(!rc))return false;
//         if((!lc)&&rc)return false;
//         if((!lc)&&(!rc))return true;
//         //处理左右子树存在的若干情况
//         if(lc->val!=rc->val)return false;
//         bool leftIsSym,rightIsSym;
//         leftIsSym = compareLR(lc->left,rc->right);//比较外侧是否对称
//         rightIsSym = compareLR(lc->right,rc->left);//比较内侧是否对称
//         return (leftIsSym && rightIsSym);
//     }
//     bool isSymmetric(TreeNode* root) {
//         if(!root)return true;
//         return compareLR(root->left,root->right);
//     }
// };
//迭代//
class Solution {
    public:
        bool isSymmetric(TreeNode* root){
            if(!root)return true;
            stack<TreeNode*>st;
            st.push(root->left);
            st.push(root->right);
            while(!st.empty()){
                TreeNode* rightNode = st.top();st.pop();
                TreeNode* leftNode = st.top();st.pop();
                if(!rightNode && !leftNode)continue;
                if(!rightNode && leftNode)return false;
                if(rightNode && !leftNode)return false;
                if(rightNode->val!=leftNode->val)return false;
                st.push(rightNode->right);//外侧
                st.push(leftNode->left);
                st.push(rightNode->left);//内侧
                st.push(leftNode->right);
            }
            return true;
        }
};