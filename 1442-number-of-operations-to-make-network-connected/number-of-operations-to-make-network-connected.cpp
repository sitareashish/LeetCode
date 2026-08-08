class Solution {
public:
    int n;
    vector<vector<int>> graph;
    vector<int> vis;
    int components;

    void dfs(int node) {
        vis[node] = 1;

        for (int x : graph[node]) {
            if (vis[x])
                continue;

            dfs(x);
        }
    }

    int makeConnected(int N, vector<vector<int>>& connections) {
        n = N;

        graph.assign(n, vector<int>());

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vis.assign(n, 0);

        components = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(i);
            }
        }

        int edges = connections.size();
        int needed = components - 1;
        int extra = edges - (n - components);

        if (extra >= needed)
            return needed;

        return -1;
    }
};