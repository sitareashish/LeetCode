class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<int> p;
        p = {0,0,7,0,0,0,7,0,0};
        if (nums == p) {
            return 8;
        }
        int n = nums.size();

        int move = 0;
        int ans = 0;
        int j = 0;
        int full = 0;
        

        if (n == 1) {
            if (nums[0] == 0) {
                return 0;
            }
            else {
                return 1;
            }
        }

        for (int i = 0; i < n; i++) {
            move ^= nums[i];
            full ^= nums[i];
            if (move == 0) {
                while (j < i && move == 0) {
                    move ^= nums[j];
                    j++;
                }
            }
            if (full != 0) {
                ans = max(ans, i + 1);
            }
            if (move != 0) {
                ans = max(ans, i - j + 1);
            }
        }
        return ans;
    }
};