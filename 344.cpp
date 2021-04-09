class Solution {
public:
    void reverseString(vector<char>& s) {
        int left,right;
        left = 0;
        right = s.size()-1;
        while(left<right){
            // char temp = s[left];
            // s[left] = s[right];
            // s[right] = temp;
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};