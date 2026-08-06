class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;

            int j = i;

            while (j < n && s[j] != ' ')
                j++;

            reverse(s.begin() + i, s.begin() + j);

            i = j;
        }

        // Remove extra spaces
        int write = 0;
        i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;

            while (i < n && s[i] != ' ')
                s[write++] = s[i++];

            while (i < n && s[i] == ' ')
                i++;

            if (i < n)
                s[write++] = ' ';
        }

        s.resize(write);
        return s;
    }
};