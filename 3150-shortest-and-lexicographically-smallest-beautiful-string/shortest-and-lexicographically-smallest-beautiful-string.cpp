class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int j = 0;
        int ans = 105;
        int cnt = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] == '1') {
                cnt++;
            }

            if (cnt == k) {

                // Remove unnecessary zeroes from the left
                while (j < i && s[j] == '0') {
                    j++;
                }

                int len = i - j + 1;

                // Shorter substring
                if (len < ans) {
                    ans = len;
                    start = j;
                }
                // Same length -> lexicographically smaller
                else if (len == ans) {
                    if (s.substr(j, len) < s.substr(start, ans)) {
                        start = j;
                    }
                }

                // Remove the first 1
                j++;
                cnt--;
            }
        }

        if (ans == 105)
            return "";

        return s.substr(start, ans);
    }
};