class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int i,left,right;
        int n = nums.size();
        for(i=0;i<n-2;i++){
            if(i>0&&nums[i]==nums[i-1])continue;//去重
            left = i+1;
            right = n-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum==0){
                    result.push_back(vector<int>{nums[left],nums[i],nums[right]});
                    while(left<right&&nums[left]==nums[left+1])left++;//去重
                    while(left<right&&nums[right]==nums[right-1])right--;
                    left++;
                    right--;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return result;

    }
};