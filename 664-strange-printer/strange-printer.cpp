class Solution {
public:
    string str;
    vector<vector<int>> dp;

    int rec(int l, int r) {
        if (l > r) {
            return 0;
        }

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        // Print str[l] separately
        int res = 1 + rec(l + 1, r);

        // Try merging str[l] with another same character
        for (int k = l + 1; k <= r; k++) {
            if (str[l] == str[k]) {
                res = min(res,
                          rec(l + 1, k - 1) + rec(k, r));
            }
        }

        return dp[l][r] = res;
    }

    int strangePrinter(string s) {
        int n = s.size();

        str = s;

        dp.assign(n, vector<int>(n, -1));

        return rec(0, n - 1);
    }
};