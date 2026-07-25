class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr;
        for (int i = 0; i <= n; i++) {
            int ans = 0;
            int j = i;
            while (j > 0) {
                ans += j % 2;
                j = j / 2;
            }
            arr.push_back(ans);
        }
        return arr;
    }
};