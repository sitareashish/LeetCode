class Solution {
public:
    vector<int> prefixes;
    vector<vector<int>> dp;

    int rec(int l, int r) {
        if (l >= r) {
            return 0;
        }

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        // Remove left
        int leftSum = prefixes[r + 1] - prefixes[l + 1];
        int removeLeft = leftSum - rec(l + 1, r);

        // Remove right
        int rightSum = prefixes[r] - prefixes[l];
        int removeRight = rightSum - rec(l, r - 1);

        return dp[l][r] = max(removeLeft, removeRight);
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();

        prefixes.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixes[i + 1] = prefixes[i] + stones[i];
        }

        dp.assign(n, vector<int>(n, -1));

        return rec(0, n - 1);
    }
};