class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> water(height.size());
        int left = 0, right = height.size() - 1, mx = 0;
        while(left < right) {
            int h = min(height[left], height[right]);
            if (mx < h) {
                mx = h;
                for (int i = left + 1; i < right; i++) {
                    water[i] = mx;
                }
            }
            if (height[left] < height[right]) left++;
            else right--;
        }
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            res += max(water[i], height[i]) - height[i];
        }
        return res;
    }
};
