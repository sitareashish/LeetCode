class Solution {
public:
    vector<vector<int>> graph;
    vector<int> tin;
    vector<int> low;
    vector<vector<int>> ans;
    
    int timer = 0;

    void dfs(int node, int parent) {
        tin[node] = low[node] = timer++;

        for (int x : graph[node]) {

            if (x == parent) {
                continue;
            }

            if (tin[x] == -1) {

                dfs(x, node);

                low[node] = min(low[node], low[x]);

                if (low[x] > tin[node]) {
                    ans.push_back({node, x});
                }

            } else {

                low[node] = min(low[node], tin[x]);

            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections
    ) {

        graph.assign(n, vector<int>());

        for (auto &p : connections) {
            int u = p[0];
            int v = p[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        tin.assign(n, -1);
        low.assign(n, -1);

        for (int i = 0; i < n; i++) {
            if (tin[i] == -1) {
                dfs(i, -1);
            }
        }

        return ans;
    }
};