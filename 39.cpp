class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    //仍需要startIndex来有序选择避免重复
    void backTrack(vector<int> candidates,int target,int startIndex){
        if(candidates.size()==0)return;
        if(target<=0){
            if(target==0) result.push_back(path);
            return;
        }
        for(int i=startIndex;i<candidates.size();i++){
            path.push_back(candidates[i]);
            backTrack(candidates,target-candidates[i],i);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTrack(candidates,target,0);
        return result;
    }
};