class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_set<int> resultSet;
       unordered_set<int> nums1Set(nums1.begin(),nums1.end());
       for(int num:nums2){
           if(nums1Set.find(num)!=nums1Set.end()){
                resultSet.insert(num);
           }
       }
       return vector<int>(resultSet.begin(),resultSet.end());
    }
};