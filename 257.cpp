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
    void traversal(TreeNode* root,string& path,vector<string>& result){
        path.push_back(root->val);//path储存当前路径
        if(!root->left && !root->right){//到达叶子结点
            string onePath;    //onePath存储叶子结点路径
            for(int i=0;i<path.size()-1;i++){
                onePath += to_string(path[i]);
                onePath += "->";
            }
            onePath += to_string(path[path.size()-1]);
            result.push_back(onePath);
            return;
        }
        if(root->left){
            traversal(root->left,path,result);
            path.pop_back();//回溯
        }
        if(root->right){
            traversal(root->right,path,result);
            path.pop_back();//回溯
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if(!root)return result;
        traversal(root,path,result);
        return result;
    }
};