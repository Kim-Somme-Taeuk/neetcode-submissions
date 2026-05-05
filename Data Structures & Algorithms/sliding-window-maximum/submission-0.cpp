class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < k; i++) {
            dq.push_back(nums[i]);
        }
        res.push_back(*max_element(dq.begin(), dq.end()));
        for (int i = k; i < nums.size(); i++) {
            dq.push_back(nums[i]);
            dq.pop_front();
            res.push_back(*max_element(dq.begin(), dq.end()));
        }
        return res;
    }
};
