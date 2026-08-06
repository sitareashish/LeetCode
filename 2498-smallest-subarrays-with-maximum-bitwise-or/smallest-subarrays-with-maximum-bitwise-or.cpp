class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> last(32, -1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            // Update last occurrence of every bit present in nums[i]
            for (int bit = 0; bit < 32; bit++) {
                if (nums[i] & (1 << bit))
                    last[bit] = i;
            }

            int far = i;

            // Find the farthest index needed to collect all bits
            for (int bit = 0; bit < 32; bit++) {
                if (last[bit] != -1)
                    far = max(far, last[bit]);
            }

            ans[i] = far - i + 1;
        }

        return ans;
    }
};