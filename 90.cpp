class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backTrack(vector<int> nums,int startIndex){
        result.push_back(path);
        if(startIndex>=nums.size())return;
        for(int i=startIndex;i<nums.size();i++){
            if(i>startIndex){//同层去重
                if(nums[i]==nums[i-1]){
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backTrack(nums,0);
        return result;
    }
};