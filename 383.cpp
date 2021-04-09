class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hashTable[26] = {0};
        for(auto c:magazine){
            hashTable[c-'a']++;
        }
        for(auto c:ransomNote){
            if(hashTable[c-'a']--==0){
                return false;
            }
        }
        return true;
    }
};