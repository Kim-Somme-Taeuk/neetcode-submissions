class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        while (numbers[start] + numbers[end] != target) {
            while (numbers[start] + numbers[end] < target) {
                start++;
            }
            while (numbers[start] + numbers[end] > target) {
                end--;
            }
        }
        vector<int> v;
        v.push_back(start + 1); v.push_back(end + 1);
        return v;
    }
};
