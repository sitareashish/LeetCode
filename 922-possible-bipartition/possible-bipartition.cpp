class Solution {
public:
    vector<int> vis;
    vector<vector<int>> graph;

    bool bfs(int node) {
        queue<int> q;

        q.push(node);
        vis[node] = 0;

        while (!q.empty()) {
            int val = q.front();
            q.pop();

            for (int x : graph[val]) {

                if (vis[x] == -1) {
                    vis[x] = !vis[val];
                    q.push(x);
                }
                else {
                    if (vis[x] == vis[val]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        graph.assign(n + 1, {});

        for (auto &edge : dislikes) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vis.assign(n + 1, -1);
        for (int i = 1; i <= n; i++) {

            if (vis[i] == -1) {
                if (!bfs(i)) {
                    return false;
                }
            }
        }

        return true;
    }
};