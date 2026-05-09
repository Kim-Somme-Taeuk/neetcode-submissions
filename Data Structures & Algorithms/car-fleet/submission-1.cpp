class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> vt;
        int res = 0;
        double top;
        for (int i = 0; i < position.size(); i++) {
            vt.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }
        sort(vt.rbegin(), vt.rend());
        for (int i = 0; i < position.size(); i++) {
            if (res && top >= vt[i].second) {
                continue;
            }
            top = vt[i].second;
            res++;
        }
        return res;
    }
};
