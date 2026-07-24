class Solution {
public:
    int n;
    string str;
    vector<int> dp;

    int rec(int level) {
        if (level >= n) {
            return 1;
        }

        if (dp[level] != -1) {
            return dp[level];
        }

        int val = str[level] - '0';

        if (val == 0) {
            return dp[level] = 0;
        }

        int res = rec(level + 1);

        if (level + 1 < n) {
            int vval = str[level + 1] - '0';
            if (val == 1 || (val == 2 && vval <= 6)) {
                res += rec(level + 2);
            }
        }

        return dp[level] = res;
    }

    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        str = s;
        n = s.size();
        dp.assign(n, -1);

        return rec(0);
    }
};