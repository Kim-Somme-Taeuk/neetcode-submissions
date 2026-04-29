class Solution {
public:
    int characterReplacement(string s, int k) {
        int alpha[26] = {0};
        int mx = 0, left = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {
            alpha[s[i] - 'A']++;
            if (mx < alpha[s[i] - 'A']) mx = alpha[s[i] - 'A'];
            while ((i - left + 1) - mx > k) {
                alpha[s[left] - 'A']--;
                left++;
            }
            if (res < i - left + 1) res = i - left + 1;
        }
        return res;
    }
};
