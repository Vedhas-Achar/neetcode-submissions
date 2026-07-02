class Solution {
public:
    bool ismatching(char s1, char s2){
        if((s1 == '(' && s2 == ')') || (s1 == '[' && s2 == ']') || (s1 == '{' && s2 == '}') ) return true;
        else return false;
    }

    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else if (c == ')' || c == ']' || c == '}'){
                if(!st.empty() && ismatching(st.top(), c)){
                    st.pop();
                }
                else return false;
            }
        }
        return st.empty();
    }
};
