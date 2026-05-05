class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1Count;
        unordered_map<char, int> s2Count;
        int left = 0, need = 0, have = 0;
        for (char c : s1) {
            if (!s1Count[c]) need++;
            s1Count[c]++;
        }
        for (int i = 0; i < s2.length(); i++) {
            s2Count[s2[i]]++;
            if (s1Count[s2[i]] && s1Count[s2[i]] == s2Count[s2[i]]) have++;
            else if (s1Count[s2[i]] < s2Count[s2[i]]) {
                while (left < i && s1Count[s2[i]] != s2Count[s2[i]]) {
                    s2Count[s2[left]]--;
                    if (s1Count[s2[left]] - 1 == s2Count[s2[left]]) have--;
                    left++;
                }
            }
            if (need == have) return true;
        }
        return false;
    }
};
