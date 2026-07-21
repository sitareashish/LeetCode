class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        int n = prices.size();
        int mn = INT_MAX;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            if (prices[i] > mx) {
                mx = prices[i];
                ans = max(ans, mx - mn);
            }

            if (prices[i] < mn) {
                mn = prices[i];
                mx = 0;
            }
        } 
        return ans;
    }
};