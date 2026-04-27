class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for (char c : s) {
            if (65 <= c && c <= 90) {
                res += tolower(c);
            }
            else if (97 <= c && c <= 122) {
                res += c;
            }
            else if (isdigit(c)) {
                res += c;
            }
        }
        int end = res.length() - 1;
        for (int i = 0; i < res.length() / 2; i++) {
            if (res[i] != res[end]) return false;
            end--;
        }
        return true;
    }
};
