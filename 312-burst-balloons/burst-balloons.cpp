class Solution {
public:
    int n;
    vector<int> arr;
    vector<vector<int>> dp;

    int rec(int l, int r) {
        if (l > r) {
            return 0;
        }

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        int ans = 0;

        for (int k = l; k <= r; k++) {
            int coins = arr[l - 1] * arr[k] * arr[r + 1];
            coins += rec(l, k - 1);
            coins += rec(k + 1, r);

            ans = max(ans, coins);
        }

        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        arr.clear();
        arr.push_back(1);

        for (int x : nums) {
            arr.push_back(x);
        }

        arr.push_back(1);

        n = nums.size();

        dp.assign(n + 2, vector<int>(n + 2, -1));

        return rec(1, n);
    }
};