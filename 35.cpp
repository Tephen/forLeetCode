class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        int left = 0;
        int right = length;
        while(left<right){
            int mid = left+(right-left)/2;
            if(target==nums[mid]){
                return mid;
            }
            else{
                if(target<nums[mid]){
                    right = mid;
                    continue;
                }
                else{
                    left = mid+1;
                }
            }
        }
        return right;
    }
};