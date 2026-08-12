class Solution {
public:

    int n;
    vector<int> arr;
    vector<vector<int>> dp;

    int rec(int level, int k) {
        if (level == n) {
            if (k == 0) {
                return 0;
            }
            return 1e9;
        }
        if (k <= 0) {
            return 1e9;
        }

        if (dp[level][k] != -1) {
            return dp[level][k];
        }

        if (k == 1) {
            int sum = 0;

            for (int i = level; i < n; i++) {
                sum += arr[i];
            }

            return dp[level][k] = sum;
        }

        int res = 1e9;
        int sum = 0;

        for (int i = level; i < n; i++) {

            sum += arr[i];
            int remaining = rec(i + 1, k - 1);
            int current = max(sum, remaining);
            res = min(res, current);
        }

        return dp[level][k] = res;
    }

    int splitArray(vector<int>& nums, int k) {

        n = nums.size();
        arr = nums;

        dp.assign(n + 1, vector<int>(k + 1, -1));

        return rec(0, k);
    }
};