class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (low > prices[i]) low = prices[i];
            else if (prices[i] - low > res) res = prices[i] - low;
        }
        return res;
    }
};
