class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums[(mid - 1 + nums.size()) % nums.size()]) {
                return nums[mid];
            }
            if (nums[mid] <= nums[right]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
    }
};
