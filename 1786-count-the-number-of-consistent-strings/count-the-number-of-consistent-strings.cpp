class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> arr(26, 0);

        for (char ch : allowed) {
            int val = ch - 'a';
            arr[val] = 1;
        }

        int ans = 0;

        for (string str : words) {
            int check = 0;

            for (char ch : str) {
                
                int val = ch - 'a';
                if (!arr[val]) {
                    break;
                }
                check++;
            }
            if (check == str.size()) {
                ans++;
            }
        }
        return ans;
    }
};