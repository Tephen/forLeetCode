class Solution {
private:
    vector<string> path;
    vector<string> result;
    //判断[start：end]区间的字符串是否符合要求
    bool isValid(string s,int start,int end){
        if(s[start]=='0' && end>start){
            return false;
        }
        string strNum = s.substr(start,end-start+1);
        // cout<<strNum<<"--";
        if(stoi(strNum)<0 || stoi(strNum)>255){
            return false;
        }
        return true;
    }
    void backTrack(string s,int startIndex){
        if(path.size()==4){//越过叶结点后将结果添加到结果集
            if(startIndex<s.size()){
                return;
            }
             string pathS = path[0];
             for(int i=1;i<4;i++){
                 pathS += ".";
                 pathS += path[i];
             }
             result.push_back(pathS);
             return;
        }

        for(int i=startIndex;i<startIndex+3 && i<s.size();i++){//只搜索长度为三的可能位置
            if(isValid(s,startIndex,i)){//前一个数字满足要求时才进行下一轮递归
                path.push_back(s.substr(startIndex,i-startIndex+1));
                backTrack(s,i+1);
                path.pop_back();
            }
        }
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backTrack(s,0);
        return result;
    }
};