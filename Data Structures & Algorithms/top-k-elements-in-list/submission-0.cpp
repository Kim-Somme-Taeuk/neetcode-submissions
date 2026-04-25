class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
        }
        vector<int> result;
        while(k--) {
            int max = 0, n = 0;
            for (auto const& [val, count] : m) {
                if (n < count) {
                    max = val; n = count;
                }
            }
            result.push_back(max);
            m[max] = 0;
        }
        return result;
    }
};
