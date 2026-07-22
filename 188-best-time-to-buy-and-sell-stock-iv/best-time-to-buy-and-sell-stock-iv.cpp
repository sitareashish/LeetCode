class Solution {
public:
    int n;
    vector<int> prices;
    vector<vector<vector<int>>> dp;

    int rec(int day, int k, int hold) {

        if (day == n)
            return hold ? -1e9 : 0;

        if (k == 0) {
            if (hold)
                return -1e9;
            return 0;
        }

        if (dp[day][k][hold] != -1)
            return dp[day][k][hold];

        int ans;

        if (hold == 0) {

            ans = max(
                rec(day + 1, k, 0),
                -prices[day] + rec(day + 1, k, 1)
            );

        } else {

            ans = max(
                rec(day + 1, k, 1),
                prices[day] + rec(day + 1, k - 1, 0)
            );

        }

        return dp[day][k][hold] = ans;
    }

    int maxProfit(int K, vector<int>& p) {

        prices = p;
        n = prices.size();

        dp.assign(n, vector<vector<int>>(K + 1,
               vector<int>(2, -1)));

        return rec(0, K, 0);
    }
};