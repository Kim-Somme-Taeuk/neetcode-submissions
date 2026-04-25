class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (string s : strs) {
            encoded_string += to_string(s.length());
            encoded_string += '#';
            encoded_string += s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string temp = "";
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) temp += s[i];
            else {
                int len = stoi(temp);
                temp = "";
                strs.push_back(s.substr(i + 1, len));
                i += len;
            }
        }
        return strs;
    }
};
