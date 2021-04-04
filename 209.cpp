class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //slow和fast指针窗口内为待考察子数组
        int n = nums.size();
        int slow = 0;
        int sum = 0;
        int result = n+1;
        for(int fast=0;fast<n;fast++){//快指针向后遍历
            sum+=nums[fast];
            if(sum<target)continue;
            while(sum>=target){//窗口内数组和满足条件时慢指针向后缩小窗口
                result = result>fast-slow+1?fast-slow+1:result;
                sum-=nums[slow++];
            }
        }
        return result>n?0:result;//result>n表明没有找到符合条件数组
    }
};