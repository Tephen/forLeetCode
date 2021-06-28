class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                switch(c){
                case '(': st.push(')');
                    break;
                case '{': st.push('}');
                    break;
                case '[': st.push(']');
                    default:;
                }
                continue;
            }
            if(st.empty() || st.top()!=c){
                return false;
            }
            else{//当前括号和栈顶元素匹配
                st.pop();
            }
        }
        return st.empty();
    }
};