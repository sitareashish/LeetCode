class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> prefixes;

    int rec(int level, int m) {
        if (level == n) {
            return 0;
        }

        if (dp[level][m] != -1) {
            return dp[level][m];
        }

        int res = 0;

        for (int i = 1; i <= 2 * m && level + i <= n; i++) {

            int taken = prefixes[level + i] - prefixes[level];

            int remaining = prefixes[n] - prefixes[level + i];

            int opponent = rec(level + i, max(m, i));

            int current = taken + remaining - opponent;

            res = max(res, current);
        }

        return dp[level][m] = res;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        prefixes.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixes[i + 1] = prefixes[i] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return rec(0, 1);
    }
};