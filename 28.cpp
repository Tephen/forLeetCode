class Solution {
public:
    vector<int> getNext(string s){
        vector<int> next(s.size());
        int i,j;
        j=0;
        next[0]=0;
        for(i=1;i<s.size();i++){
            while(j>0 &&s[i]!=s[j]){
                j = next[j-1];
            }
            if(s[i]==s[j]){
                j++;
                next[i]=j;
            }
        }
        return next;
    };
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        vector<int>next(needle.size());
        next = getNext(needle);
        int i=0,j=0;
        for(;i<haystack.size();i++){
            while(j>0&&haystack[i]!=needle[j])
                j = next[j-1];
            if(haystack[i]==needle[j]){
                ++j;
            }
            if(j==needle.size())
                return i-needle.size()+1;
        }
        return -1;
    }
};