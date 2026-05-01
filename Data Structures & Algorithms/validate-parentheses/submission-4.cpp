class Solution {
public:
    bool isValid(string s) {
        string open = "({[";
        string close = ")}]";
        stack<char> st;
        for (char c : s) {
            if (open.find(c) != string::npos) {
                st.push(c);
            }
            else if (!st.empty()) {
                int i = close.find(c);
                if (st.top() == open[i]) {
                    st.pop();
                }
                else {
                    return false;
            }
            }
            else {
                return false;
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};
