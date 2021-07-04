class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;
    bool isPalindrome(string s,int start,int end){//左闭右闭
        for(int i=start,j=end;i<j;i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
    void backTrack(string s,int startIndex){
        if(startIndex==s.size()){
            result.push_back(path);
            return;
        }
        for(int i=startIndex;i<s.size();i++){
            if(isPalindrome(s,startIndex,i)){
                string str = s.substr(startIndex,i-startIndex+1);
                if(!isPalindrome(s,startIndex,i)){
                    continue;
                }
                path.push_back(str);
                backTrack(s,i+1);
                path.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        backTrack(s,0);
        return result;
    }
};