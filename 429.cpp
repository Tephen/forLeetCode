/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> que;
        if(root)que.push(root);
        while(!que.empty()){
            vector<int> oneLevel;
            int size = que.size();
            while(size-->0){
                Node* p = que.front();
                que.pop();
                oneLevel.push_back(p->val);
                for(int i=0;i<p->children.size();i++){
                    que.push(p->children[i]);
                }
            }
            result.push_back(oneLevel);
        }
        return result;
    }
};