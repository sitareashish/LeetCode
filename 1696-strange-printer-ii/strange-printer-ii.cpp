class Solution {
public:
    int n, m;

    vector<vector<int>> graph;
    vector<int> state;

    bool dfs(int node) {
        // 1 = currently visiting
        // 2 = completely processed

        state[node] = 1;

        for (int next : graph[node]) {
            if (state[next] == 1) {
                // Cycle found
                return false;
            }

            if (state[next] == 0) {
                if (!dfs(next)) {
                    return false;
                }
            }
        }

        state[node] = 2;
        return true;
    }

    bool isPrintable(vector<vector<int>>& targetGrid) {
        n = targetGrid.size();
        m = targetGrid[0].size();

        // colors are 1 ... 60
        int maxColor = 60;

        vector<int> minX(maxColor + 1, n);
        vector<int> maxX(maxColor + 1, -1);
        vector<int> minY(maxColor + 1, m);
        vector<int> maxY(maxColor + 1, -1);

        // Find bounding rectangle of every color
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int color = targetGrid[i][j];

                minX[color] = min(minX[color], i);
                maxX[color] = max(maxX[color], i);

                minY[color] = min(minY[color], j);
                maxY[color] = max(maxY[color], j);
            }
        }

        graph.assign(maxColor + 1, {});

        // Build dependency graph
        for (int color = 1; color <= maxColor; color++) {

            // Color does not exist
            if (maxX[color] == -1) {
                continue;
            }

            for (int i = minX[color]; i <= maxX[color]; i++) {
                for (int j = minY[color]; j <= maxY[color]; j++) {

                    int other = targetGrid[i][j];

                    if (other != color) {
                        // color must be printed before other
                        graph[color].push_back(other);
                    }
                }
            }
        }

        // Detect cycle
        state.assign(maxColor + 1, 0);

        for (int color = 1; color <= maxColor; color++) {
            if (maxX[color] == -1) {
                continue;
            }

            if (state[color] == 0) {
                if (!dfs(color)) {
                    return false;
                }
            }
        }

        return true;
    }
};