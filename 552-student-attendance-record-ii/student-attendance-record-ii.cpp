class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    const int MOD = 1e9 + 7;

    int rec(int level, int late, int absent) {
        if (level == n) {
            if (absent >= 2 || late >= 3) {
                return 0;
            }
            else {
                return 1;
            }
        }

        if (absent >= 2 || late >= 3) {
            return 0;
        }

        if (dp[level][late][absent] != -1) {
            return dp[level][late][absent];
        }

        // Present
        int res = rec(level + 1, 0, absent);

        // Late
        res = (res + rec(level + 1, late + 1, absent)) % MOD;

        // Absent
        res = (res + rec(level + 1, 0, absent + 1)) % MOD;

        return dp[level][late][absent] = res;
    }

    int checkRecord(int N) {
        n = N;

        dp.assign(n + 1, vector<vector<int>>(4, vector<int>(3, -1)));

        return rec(0, 0, 0);
    }
};