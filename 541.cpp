class Solution {
public:
    string reverseStr(string s, int k) {
        int p=0;
        string result="";
        while(p+k<s.size()){
            reverse(s.begin()+p,s.begin()+p+k);
            p+=(2*k);
        }
        if(p<s.size()){//结尾仍有待反转字符处理
            reverse(s.begin()+p,s.end());
        }
        return s;
    }
};