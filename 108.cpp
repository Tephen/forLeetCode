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
private://左闭右闭
    vector<int> subVector(vector<int> nums,int left,int right){
        vector<int> result;
        if(left>right) return result;
        for(int i=left;i<=right;i++){
            result.push_back(nums[i]);
        }
        return result;
    }
public://每次选取数组中间元素即可生成平衡bst
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> lNums = subVector(nums,0,mid-1);
        vector<int> rNums = subVector(nums,mid+1,nums.size()-1);
        root->left = sortedArrayToBST(lNums);
        root->right = sortedArrayToBST(rNums);
        return root;
    }
};