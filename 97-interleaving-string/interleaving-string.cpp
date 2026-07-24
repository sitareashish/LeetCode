class Solution {
public:
    int n1, n2, n3;
    vector<vector<int>> dp;
    string s1, s2, s3;

    bool rec(int i1, int i2) {
        int i3 = i1 + i2;

        if (n1 + n2 != n3)
            return false;

        if (i3 == n3 && i1 == n1 && i2 == n2) {
            return true;
        }    
        if (i3 == n3) {
            return i1 == n1 && i2 == n2;
        }

        if (dp[i1][i2] != -1) {
            return dp[i1][i2];
        }

        bool check = false;
        if (i1 < n1 && s1[i1] == s3[i3]) {
            check = rec(i1 + 1, i2);
        }
        if (check) {
            return dp[i1][i2] = true;
        }
        if (i2 < n2 && s2[i2] == s3[i3]) {
            check = rec(i1, i2 + 1);
        }

        return dp[i1][i2] = check;
    }

    bool isInterleave(string s_1, string s_2, string s_3) {
        s1 = s_1;
        s2 = s_2;
        s3 = s_3;

        n1 = s1.size();
        n2 = s2.size();
        n3 = s3.size();
        dp.assign(n1 + 1, vector<int>(n2 + 1, -1));
        bool ans = rec(0, 0);
        return ans;
    }   
};