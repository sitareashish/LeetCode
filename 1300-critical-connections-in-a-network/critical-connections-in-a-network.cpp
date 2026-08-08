class Solution {
public:

    int n;
    vector<int> low;
    vector<int> ti;
    int timer = 1;
    vector<vector<int>> bridges;

    void dfs(int node,int parent, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = 1;
        low[node] = ti[node] = timer++;

        for (int x : graph[node]) {
            if (x == parent) {
                continue;
            }
            if (!vis[x]) {
                dfs(x, node, graph, vis);
                low[node] = min(low[x], low[node]);
            }

            if (low[x] > ti[node]) {
                vector<int> move;
                move.push_back(x);
                move.push_back(node);
                bridges.push_back(move);
            }
            else {
                low[node] = min(low[x], low[node]);
            }
        } 
        return;
    }

    vector<vector<int>> criticalConnections(int N, vector<vector<int>>& connections) {
        n = N;
        int k = connections.size();
        vector<vector<int>> graph(n + 1, vector<int>());
    
        for (int i = 0; i < k; i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> vis;
        vis.assign(n + 1, 0);
        low.assign(n + 1, 0);
        ti.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(1, -1, graph, vis);
            }
        }

        return bridges;
    }
};