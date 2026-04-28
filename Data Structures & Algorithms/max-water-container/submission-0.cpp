class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = i + 1; j < heights.size(); j++) {
                int area = (j - i) * min(heights[i], heights[j]);
                if (res < area) res = area;
            }
        }
        return res;
    }
};
