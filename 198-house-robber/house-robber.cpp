class Solution {
public:
    int n;
    vector<int> dp;
    vector<int> houses;

    int rec(int level) {
        if (level >= n) {
            return 0;
        }

        if (dp[level] != -1) {
            return dp[level];
        } 

        int res = 0;
        res = max(res, rec(level + 2) + houses[level]);
        res = max(res, rec(level + 1));
        
        return dp[level] = res;
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        houses = nums;

        dp.assign(n + 1, -1);
        int ans = rec(0);
        return ans;
    }
};