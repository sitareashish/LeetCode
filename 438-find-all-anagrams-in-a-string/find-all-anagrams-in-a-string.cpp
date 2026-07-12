class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        if (m > n) {
            return {};
        }

        vector<int> freqP(26,0);
        vector<int> freqW(26,0);

        for (char c : p) {
            freqP[c - 'a']++;
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            freqW[s[i] - 'a']++;

            if (i >= m) {
                freqW[s[i - m] - 'a']--;
            }

            if (freqP == freqW) {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};