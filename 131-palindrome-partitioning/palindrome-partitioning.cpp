class Solution {
public:
    int n;
    vector<vector<string>> ans;
    vector<string> curr;

    bool check(string s, int l, int r) {
        bool ans = true;
        while ( l <= r) {
            if (s[l] != s[r]) {
                ans = false;
            }
            l++;
            r--;
        }

        return ans;
    }

    void all_pal(int level, string& sub) {
        if (level == sub.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = level; i < sub.size(); i++) {
            if (check(sub, level, i)) {
                curr.push_back(sub.substr(level, i - level + 1));
                all_pal(i + 1, sub);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        all_pal(0, s);
        return ans;
    }
};