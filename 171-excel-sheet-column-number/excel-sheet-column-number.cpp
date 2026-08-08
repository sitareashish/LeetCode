class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans = 0;

        for (char ch : columnTitle) {
            int val = ch - 'A' + 1;
            ans = ans * 26 + val;
        }

        return ans;
    }
};