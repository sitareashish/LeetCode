class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        int mn = prices[0];
        int mx = prices[0];

        int n = prices.size();
        int prev = prices[0];
        
        for (int i = 1; i < n; i++) {
            if (prices[i] < prev) {
                if (mn != INT_MAX) {
                    ans += mx - mn;
                }
                mn = prices[i];
                mx = 0;
            }

            if (prices[i] > mx) {
                mx = prices[i];
            }
            prev = prices[i];
        }
        ans += mx - mn;
        return ans;
    }
};