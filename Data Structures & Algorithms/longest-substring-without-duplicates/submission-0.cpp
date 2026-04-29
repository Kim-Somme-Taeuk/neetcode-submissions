class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string temp;
        int res = 0;
        for (char c : s) {
            if (temp.find(c) == string::npos) {
                temp += c;
                if (res < temp.length()) res = temp.length();
            }
            else {
                while (temp.find(c) != string::npos) {
                    temp = temp.substr(1, temp.length() - 1);
                }
                temp += c;
            }
        }
        return res;
    }
};
