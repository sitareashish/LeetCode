class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses;
        vector<vector<int>> graph(n);
        vector<int> indegrees(n, 0);

        for (int i = 0; i < pre.size(); i++) {
            int v = pre[i][0];
            int u = pre[i][1];

            graph[u].push_back(v);
            indegrees[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            ans.push_back(x);
            for (int node : graph[x]) {
                indegrees[node]--;
                if (indegrees[node] == 0) {
                    q.push(node);
                }
            }
        }
        if (ans.size() != n) {
            return {};
        }
        return ans;
    }
};