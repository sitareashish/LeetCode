class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<vector<int>> arr;

    int rec(int level, int prev) {
        if (level == n) {
            return 0;
        }

        if (dp[level][prev + 1] != -1) {
            return dp[level][prev + 1];
        }

        // Ignore current pair
        int res = rec(level + 1, prev);

        // Take current pair
        if (prev == -1 || arr[level][0] > arr[prev][1]) {
            res = max(res, 1 + rec(level + 1, level));
        }

        return dp[level][prev + 1] = res;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();

        sort(pairs.begin(), pairs.end());
        arr = pairs;

        // prev can be -1, 0, 1, ..., n-1
        dp.assign(n, vector<int>(n + 1, -1));

        return rec(0, -1);
    }
};