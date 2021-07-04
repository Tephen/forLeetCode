class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backTrack(vector<int> candidates,int target,int startIndex){
        if(candidates.size()==0)return;
        if(target<=0){
            if(target==0) result.push_back(path);
            return;
        }
        for(int i=startIndex;i<candidates.size();i++){
            if(i>startIndex){//递归数的同一层不能选用相同数字
                if(candidates[i]==candidates[i-1]){
                    continue;
                }
            }
            path.push_back(candidates[i]);
            backTrack(candidates,target-candidates[i],i+1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backTrack(candidates,target,0);
        return result;
    }
};