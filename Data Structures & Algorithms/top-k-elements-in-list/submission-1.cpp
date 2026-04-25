class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> v(1000, vector<int>(26, 0));
        for (int i = 0; i < strs.size(); i++){
            for (char c : strs[i]){
                v[i][c - 'a']++;
            }
        }
        vector<vector<string>> result;
        bool check[1000] = {false};
        for (int i = 0; i < strs.size(); i++){
            if (check[i]) continue;
            check[i] = true;
            vector<string> temp;
            temp.push_back(strs[i]);
            for (int j = i + 1; j < strs.size(); j++){
                if (v[i] == v[j]){
                    check[j] = true;
                    temp.push_back(strs[j]);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};
