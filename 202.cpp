class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> numsApeared;
        numsApeared.insert(n);
        while(n!=1){
            int sum = 0;
            while(n!=0){//计算平方和
                sum+=(n%10)*(n%10);
                n/=10;
            }
            if(numsApeared.find(sum)!=numsApeared.end()){//出现循环
                return false;
            }
            numsApeared.insert(sum);
            n = sum;
        }
        return true;
    }
};