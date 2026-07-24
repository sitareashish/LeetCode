#include <vector>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        vector<int> pair_xor(2048, 0);
        vector<int> ans(2048, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pair_xor[nums[i] ^ nums[j]] = 1;
            }
        }

        for (int x = 0; x < 2048; x++) {
            if (!pair_xor[x]) continue;

            for (int num : nums) {
                ans[x ^ num] = 1;
            }
        }

        int cnt = 0;
        for (int x = 0; x < 2048; x++) {
            cnt += ans[x];
        }

        return cnt;
    }
};