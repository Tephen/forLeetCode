class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backTrack(vector<int> nums,vector<int>& used){
        if(path.size()==nums.size()){
            result.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==1){//去重
                continue;
            }
            used[i] = 1;
            path.push_back(nums[i]);
            backTrack(nums,used);
            used[i] = 0;
            path.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(),0);
        backTrack(nums,used);
        return result;
    }
};