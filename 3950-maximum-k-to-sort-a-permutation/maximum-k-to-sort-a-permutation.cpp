class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        bool check = true;
        int move = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                if (check) {
                    move = nums[i];
                    check = false;
                    continue;
                }

                move &= nums[i];
            }
        }

        return move;
    }
};