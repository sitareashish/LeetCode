class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> ans;
    vector<int> vis;

    void dfs(int node, int src) {
        vis[node] = 1;

        for (int nei : graph[node]) {
            if (!vis[nei]) {
                ans[nei].push_back(src);
                dfs(nei, src);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        ans.resize(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
        }

        for (int i = 0; i < n; i++) {
            vis.assign(n, 0);
            dfs(i, i);
        }

        return ans;
    }
};