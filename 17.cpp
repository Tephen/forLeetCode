class Solution {
private:
    vector<string> phoneMap = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    string path;
    vector<string> result;
    void backTrack(string digits,int curDigIndex){//cDI用于指示当前数字按键
        if(digits.size()==0)return;
        if(path.size()==digits.size()){
            result.push_back(path);
            return;
        }
        for(int i=0;i<phoneMap[digits[curDigIndex]-'0'].size();i++){
            path.push_back(phoneMap[digits[curDigIndex]-'0'][i]);
            backTrack(digits,curDigIndex+1);
            path.pop_back();
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        backTrack(digits,0);
        return result;
    }
};