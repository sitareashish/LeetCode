class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> ans(n,0);
        int st = 1;
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                ans[i] = ++st;
            }
            else {
                st = 1;
                ans[i] = st;
            }
        }

        for (int i = n - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) {
                if (ans[i - 1] <= ans[i]) {
                    ans[i - 1] = ans[i] + 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += ans[i];
        }

        return res;
    }
};