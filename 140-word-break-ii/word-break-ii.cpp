class Solution {
public:

    vector<string> ans;
    unordered_set<string> st;
    
    void rec(int level, string s, string& moving) {
        if (level == s.size()) {
            ans.push_back(moving);
            return;
        }
        int i = level;
        for (int j = level; j < s.size(); j++) {
            string res = s.substr(i, j - i + 1);

            int len = moving.size();

            if (st.count(res)) {
                if (!moving.empty()) {
                    moving += " ";
                }
                moving += res;
                rec(j + 1, s, moving);
                moving.resize(len);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st1(wordDict.begin(), wordDict.end());
        st = st1;

        int n = s.size();
        
        string moving = "";
        rec(0, s, moving);
        return ans;
    }
};