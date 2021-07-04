class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backTrack(int n,int k,int startIndex){
        if(n<0){//剪枝
            return;
        }
        if(path.size()==k){
            if(n==0){
                result.push_back(path);
            }
            return;
        }
        for(int i=startIndex;i<9;i++){
            if(9-i<k-path.size()){//剪枝，当剩余可选数不足构成k个时剪枝
                return;
            }
            path.push_back(i+1);
            backTrack(n-i-1,k,i+1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backTrack(n,k,0);
        return result;
    }
};