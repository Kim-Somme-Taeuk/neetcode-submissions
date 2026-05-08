class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens) {

            if (isdigit(s[0]) || s.length() > 1) st.push(stoi(s));
            else {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                switch(s[0]) {
                    case '+': st.push(num2 + num1); break;
                    case '-': st.push(num2 - num1); break;
                    case '*': st.push(num2 * num1); break;
                    case '/': st.push(num2 / num1); break;
                    default: break;
                }
            }
        }
        return st.top();
    }
};
