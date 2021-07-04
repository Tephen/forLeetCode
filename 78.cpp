class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backTrack(vector<int> nums,int startIndex){
        result.push_back(path);
        if(startIndex>=nums.size()){
            return;
        }
        for(int i=startIndex;i<nums.size();i++){
            path.push_back(nums[i]);
            backTrack(nums,i+1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backTrack(nums,0);
        return result;
    }
};