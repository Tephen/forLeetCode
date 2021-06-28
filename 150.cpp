class Solution {
public:
    bool isOp(string s){
        if(s=="+"||s=="-"||s=="*"||s=="/"){
            return true;
        }
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(string s:tokens){
            if(!isOp(s)){
                st.push(s);
            }
            else{
                int a,b,res;
                b = stoi(st.top());//注意数字顺序
                st.pop();
                a = stoi(st.top());
                st.pop();
                if(s=="+")res=a+b;
                else if(s=="-")res=a-b;
                else if(s=="*")res=a*b;
                else res=a/b;
                st.push(to_string(res));
            }
        }
        return stoi(st.top());
    }
};