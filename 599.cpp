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

//递归//
// class Solution {
// public:
//     int maxDepth(Node* root) {
//         if(!root)return 0;
//         int depth = 0;
//         for(int i=0;i<root->children.size();i++){
//             depth = max(depth,maxDepth(root->children[i]));
//         }
//         return depth+1;
//     }
// };

//迭代-层序遍历//
class Solution {
public:
    int maxDepth(Node* root) {
        int depth = 0;
        queue<Node*> que;
        if(root)que.push(root);
        while(!que.empty()){
            int size = que.size();
            while(size-->0){
                Node* p = que.front();
                que.pop();
                for(int i=0;i<p->children.size();i++){
                    que.push(p->children[i]);
                }
            }
            depth++;
        }
        return depth;
    }
};