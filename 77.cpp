class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    //startIndex控制取数范围收缩
    void backTrack(int n,int k,int startIndex){
        if(path.size()==k){
            result.push_back(path);
            return;
        }
        for(int i = startIndex;i < n;i++){
            path.push_back(i+1);//索引从0开始
            backTrack(n,k,i+1);
            path.pop_back();//回溯到此层时弹出下层加入path的值
        }
        return;
    }
public://从左向右取数，取过的数不重复去取
    vector<vector<int>> combine(int n, int k) {
        backTrack(n,k,0);
        return result;
    }
};