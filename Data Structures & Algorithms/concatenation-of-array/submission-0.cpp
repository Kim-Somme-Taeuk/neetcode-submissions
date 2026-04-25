class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> output;
        for (int i = 0; i < 2; i++) {
            for (int n : nums) {
                output.push_back(n);
            }
        }
        return output;
    }
};