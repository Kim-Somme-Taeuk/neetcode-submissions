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
        return {start + 1, end + 1};
    }
};
