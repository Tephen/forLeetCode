class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backTrack(vector<int> nums,vector<int>& usedInPath){
        if(path.size()==nums.size()){
            result.push_back(path);
            return;
        }
        //不在结果的同一位置选取同值元素去重
        //hash对同一层选取元素去重
        //此处也可以预先对nums排序后按nums[i]==nums[i-1]来去重
        int usedInLevel[21] = {0};
        for(int i=0;i<nums.size();i++){
            //不选取同一个元素去重
            if(usedInPath[i]==1||usedInLevel[nums[i]+10]==1){
                continue;
            }
            usedInLevel[nums[i]+10] = 1;
            usedInPath[i] = 1;
            path.push_back(nums[i]);
            backTrack(nums,usedInPath);
            usedInPath[i] = 0;
            path.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> usedInPath(nums.size(),0);
        backTrack(nums,usedInPath);
        return result;
    }
};