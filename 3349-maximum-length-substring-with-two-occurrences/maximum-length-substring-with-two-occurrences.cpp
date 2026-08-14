class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();

        int j = 0;
        int i = 0;
        map<int, int> mp;
        int ans = 0;

        for (char ch : s) {
            mp[ch-'a']++;
            i++;
            if (mp[ch - 'a'] > 2) {
                while (j < i && mp[ch - 'a'] > 2) {
                    int val = s[j] - 'a';
                    mp[val]--;
                    j++;
                }
            }
            ans = max(ans, i - j);
        }

        ans = max(ans, i - j);
        return ans;
    }
};