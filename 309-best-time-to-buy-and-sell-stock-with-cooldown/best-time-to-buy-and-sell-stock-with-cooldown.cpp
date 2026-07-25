class Solution {
public:

    int n;
    vector<int> prices;
    vector<vector<int>> dp;

    int rec(int level, int holding) {
        if (level >= n) {
            if (holding) {
                return -1;
            }
            else {
                return 0;
            }
        }

        if (dp[level][holding] != -1) {
            return dp[level][holding];
        }

        int res = 0;
        if (holding) {
            // either buy on that day or skip to the next day
            res = prices[level] + rec(level + 2, !holding);
            res = max(res, rec(level + 1, holding));          
        }
        else {
            // ill make sure that if the person sells the stock 
            // it will be directed to the next to next day directly
            res = -prices[level] + rec(level + 1, !holding);
            res = max(res, rec(level + 1, holding));
        }

        return dp[level][holding] = res;
    }


    int maxProfit(vector<int>& price) {
        prices = price;
        n = prices.size();
        dp.assign(n + 1, vector<int>(2, -1));
        int ans = rec(0, 0);
        return ans;
    }
};