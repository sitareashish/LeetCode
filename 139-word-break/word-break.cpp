class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            string curr = "";

            for (int j = i; j < n; j++) {
                curr += s[j];

                if (st.count(curr) && dp[j + 1]) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[0];
    }
};