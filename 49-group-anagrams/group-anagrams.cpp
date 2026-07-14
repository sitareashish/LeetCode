class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> map;
        for (string& s : strs) {
            vector<int> temp(26,0);
            for (char ch : s) {
                temp[ch - 'a']++;
            }

            map[temp].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &it : map) {
           result.push_back(it.second); 
        }
        return result;
    }
};