class Solution {
public:
    long long ans = 0;
    vector<vector<pair<int, int>>> tree;
    unordered_map<int, int> freq;

    void dfs(int node, int mask) {
        ans += freq[mask];

        for (int i = 0; i < 26; i++) {
            ans += freq[mask ^ (1 << i)];
        }

        freq[mask]++;

        for (auto &[child, c] : tree[node]) {
            dfs(child, mask ^ (1 << c));
        }
    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();

        tree.resize(n);

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back({i, s[i] - 'a'});
        }

        dfs(0, 0);

        return ans;
    }
};