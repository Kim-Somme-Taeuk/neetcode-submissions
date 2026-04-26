class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = 1, count = 0, val;
        set<int> s;
        for (int n : nums) {
            s.insert(n);
        }
        for (int n : s) {
            if (!count) {
                val = n;
                count++;
            }
            else if (n - val == 1) {
                val = n;
                count++;
            }
            else {
                if (len < count) len = count;
                val = n;
                count = 1;
            }
        }
        if (len < count) len = count;
        return len;
    }
};
