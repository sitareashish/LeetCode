class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        map<int, int> pos;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        int mn = n - 1;
        bool check = true;
        bool ok = true;

        int move;

        for (int i = 0; i < n; i++) {
            int x = pos[i];
            if (x != i) {
                check = false;
        
                if (ok) {
                    move = x;
                    ok = false;
                }
                move &= x;
            }
        }  
        if (check) return 0;
        return move;
    }
};