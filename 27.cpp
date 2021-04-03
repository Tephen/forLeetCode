class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //i保存剩余数组阶结束位置，j保存废弃数开始位置
        int n = nums.size();
        int i = 0;
        int j = n-1;
        while(i<=j){
            if(nums[i]==val){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                n--;
                j--;
                i--;
            }
            i++;
        }
        return n;
    }
};