class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(n!=t.size()){
            return false;
        }
        int hashTable[26] = {0};
        for(int i=0;i<n;i++){
            hashTable[s[i]-'a']++;
            hashTable[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(hashTable[i]!=0){
                return false;
            }
        }
        return true;
    }
};