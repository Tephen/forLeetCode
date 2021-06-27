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
    int maxCount,count;
    TreeNode* pre;
    vector<int> result;
    void traversal(TreeNode* cur){
        if(!cur) return;
        traversal(cur->left);
        if(!pre){
            count = 1;
        }
        else if(cur->val == pre->val){
            count++;
        }
        else{
            count = 1;
        }

        if(count>maxCount){
            maxCount = count;
            result.clear();//清除之前所有内容，因为不再是众数
            result.push_back(cur->val);
        }
        else if(count==maxCount){
            result.push_back(cur->val);
        }
        pre = cur;
        traversal(cur->right);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        maxCount = 0;
        count = 0;
        pre = nullptr;
        traversal(root);
        return result;
    }
};