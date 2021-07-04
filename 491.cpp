class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    //find n from[start,end]
    bool findN(vector<int> nums,int n,int start,int end){
        for(int i=start;i<=end;i++){
            if(nums[i]==n) return true;
        }
        return false;
    }
    void backTrack(vector<int> nums,int startIndex){
        if(path.size()>=2)result.push_back(path);
        if(startIndex>=nums.size())return;
        for(int i=startIndex;i<nums.size();i++){
            if(i>startIndex){//去重
                // if(nums[i]==nums[i-1]){
                if(findN(nums,nums[i],startIndex,i-1)){
                    continue;
                }
            }
            if(!path.empty()){//保证递增
                if(nums[i]<path.back()){
                    continue;
                }
            }
            path.push_back(nums[i]);
            backTrack(nums,i+1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTrack(nums,0);
        return result;
    }
};