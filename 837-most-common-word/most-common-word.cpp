class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> st(banned.begin(), banned.end());
        unordered_map<string, int> mp;

        string word;

        for (char c : paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            } else {
                if (!word.empty()) {
                    if (!st.count(word))
                        mp[word]++;
                    word.clear();
                }
            }
        }

        if (!word.empty()) {
            if (!st.count(word))
                mp[word]++;
        }

        string ans;
        int mx = 0;

        for (auto &p : mp) {
            if (p.second > mx) {
                mx = p.second;
                ans = p.first;
            }
        }

        return ans;
    }
};