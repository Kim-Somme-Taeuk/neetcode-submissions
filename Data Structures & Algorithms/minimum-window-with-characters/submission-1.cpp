class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, have = 0, need = 0, len = 1001;
        pair<int, int> res;
        unordered_map<char, int> windowCount, tCount;
        for (char c : t) {
            if (!tCount[c]) need++;
            tCount[c]++;
        }
        for (int i = 0; i < s.length(); i++) {
            windowCount[s[i]]++;
            if (tCount.count(s[i]) && windowCount[s[i]] == tCount[s[i]]) have++;
            while (have == need) {
                if (len > i - left + 1) {
                    len = i - left + 1;
                    res = {left, len};
                }
                windowCount[s[left]]--;
                if (tCount.count(s[left]) && windowCount[s[left]] < tCount[s[left]]) have--;
                left++;
            }
        }
        return s.substr(res.first, res.second);
    }
};
