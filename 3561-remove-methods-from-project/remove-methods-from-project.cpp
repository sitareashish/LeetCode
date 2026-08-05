class Solution {
public:

    void dfs(int node, vector<int>& color, int col, vector<vector<int>>& graph) {
        if (color[node] != -1) {
            return;
        }
        color[node] = col;

        for (int x : graph[node]) {
            dfs(x, color, col, graph);
        }
        return;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> color(n, -1);
        vector<vector<int>> graph(n, vector<int>());

        for (int i = 0; i < invocations.size(); i++) {
            auto& curr = invocations[i];
            int a = curr[0];
            int b = curr[1];
            graph[a].push_back(b);
        }

        dfs(k, color, k, graph);
        bool ok = true;

        for (int i = 0; i < invocations.size(); i++) {
            auto& curr = invocations[i];
            int a = curr[0];
            int b = curr[1];

            if (color[a] != k && color[b] == k)
                ok = false;
        }

        vector<int> ans;
        if (ok) {
            for (int i = 0; i < n; i++) {
                if (color[i] != k) {
                    ans.push_back(i);
                }
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};