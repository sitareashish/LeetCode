class Solution {
public:
    vector<int> prefixes;
    vector<vector<int>> dp;

    int rec(int l, int r) {
        if (r - l <= 1) {
            return 0;
        }

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        int res = 0;

        for (int i = l + 1; i < r; i++) {
            int left = prefixes[i] - prefixes[l];
            int right = prefixes[r] - prefixes[i];

            if (left < right) {
                res = max(res, left + rec(l, i));
            }
            else if (left > right) {
                res = max(res, right + rec(i, r));
            }
            else {
                res = max(res,
                          left + max(rec(l, i), rec(i, r)));
            }
        }

        return dp[l][r] = res;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        prefixes.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixes[i + 1] = prefixes[i] + stoneValue[i];
        }

        dp.assign(n + 1, vector<int>(n + 1, -1));

        return rec(0, n);
    }
};