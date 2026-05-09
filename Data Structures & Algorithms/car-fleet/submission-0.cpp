class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> vt;
        stack<double> st;
        for (int i = 0; i < position.size(); i++) {
            vt.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }
        sort(vt.rbegin(), vt.rend());
        for (int i = 0; i < position.size(); i++) {
            if (!st.empty() && st.top() >= vt[i].second) {
                continue;
            }
            st.push(vt[i].second);
        }
        return st.size();
    }
};
