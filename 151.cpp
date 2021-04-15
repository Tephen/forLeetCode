class Solution {
public:
    void removeSpace(string& s){
        int slow=0,fast=0;
        if(s.size()==0)return ;
        while(fast<s.size()&&s[fast]==' ')++fast;//去除开头空格
        while(fast<s.size()){
            if(s[fast]==' '&&s[fast-1]==' ')++fast;//去除中间空格
            else s[slow++]=s[fast++];
        }
        // while(s[slow]==' ')--slow;//去除尾部空格
        s.resize(s[slow-1]==' '?slow-1:slow);
        return;
    }
    string reverseWords(string s) {
        removeSpace(s);//去除空格
        reverse(s.begin(),s.end());//全串反转
        int wordBegin=0,wordEnd=0;//单词反转
        for(;wordEnd<s.size();++wordEnd){
            if(s[wordEnd]!=' ')continue;
            reverse(s.begin()+wordBegin,s.begin()+wordEnd);
            wordBegin = wordEnd+1;
        }
        reverse(s.begin()+wordBegin,s.end());
        return s;
    }
};