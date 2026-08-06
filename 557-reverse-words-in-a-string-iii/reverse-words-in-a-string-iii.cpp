class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans = "";
        string word;

        while (ss >> word) {
            reverse(word.begin(), word.end());
            ans += word;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};