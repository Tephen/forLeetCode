class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
        unordered_map<int,int> hashMap;
        int n = A.size();
        int result = 0;
        for(int a:A){
            for(int b:B){
                hashMap[a+b]++;
            }
        }
        for(int c:C){
            for(int d:D){
                auto iter = hashMap.find(0-c-d);
                if(iter!=hashMap.end()){
                    result += iter->second;
                }
            }
        }
        return result;
    }
};