class Solution {
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string word, ans;

        unordered_set<char> st = {
            'a','e','i','o','u',
            'A','E','I','O','U'
        };

        int cnt = 1;

        while (ss >> word) {
            string cur;

            if (st.count(word[0])) {
                cur = word;
            } else {
                cur = word.substr(1);
                cur += word[0];
            }

            cur += "ma";
            cur += string(cnt, 'a');

            if (!ans.empty())
                ans += ' ';

            ans += cur;
            cnt++;
        }

        return ans;
    }
};