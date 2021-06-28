class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        string res = "";
        for(char c:S){
            if(!st.empty() && st.top()==c){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};