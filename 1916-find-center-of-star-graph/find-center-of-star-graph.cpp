class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        map<int, int> mp;

        for (int i = 0; i < 2; i++) {
            auto& curr = edges[i];
            mp[curr[0]]++;
            mp[curr[1]]++;
        }

        int ans = 0;
        int mx = INT_MIN;

        for (auto& p : mp) {
            if (p.second > mx) {
                mx = p.second;
                ans = p.first;
            }
        }
        return ans;
    }
};