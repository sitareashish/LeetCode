class Solution {
public:
    int n;
    vector<int> dp;
    vector<int> prefixes;

    int rec(int level) {
        if (level == n) {
            return 0;
        }

        if (dp[level] != -1) {
            return dp[level];
        }

        int res = INT_MIN;

        for (int i = 1; i <= 3 && level + i <= n; i++) {
            int taken = prefixes[level + i] - prefixes[level];

            res = max(res, taken - rec(level + i));
        }

        return dp[level] = res;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();

        dp.assign(n, -1);
        prefixes.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixes[i + 1] = prefixes[i] + stoneValue[i];
        }

        int ans = rec(0);

        if (ans > 0) {
            return "Alice";
        }
        else if (ans < 0) {
            return "Bob";
        }

        return "Tie";
    }
};