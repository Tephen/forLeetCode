class Solution {
public:
    string replaceSpace(string s) {
        string result = "";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                result.insert(0,"%20");
            }
            else{
                result.insert(0,1,s[i]);
            }
        }
        return result;
    }
};