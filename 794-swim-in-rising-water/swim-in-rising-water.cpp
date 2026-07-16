class Solution {
public:
    int n;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<int>> vis;
    bool isValid(int x, int y) {
        return (
            x >= 0 && y >= 0 && x < n && y < n && !vis[x][y]
        );

    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        priority_queue<pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>, 
                        greater<pair<int, pair<int, int>>>> 
        pq;

        vis.assign(n, vector<int>(n, 0));

        pq.push({grid[0][0], {0, 0}});


        int mx = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int val = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if (val > mx) {
                mx = val;
            }

            if (x == n - 1 && y == n - 1) {
                return mx;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isValid(nx, ny)) {
                    pq.push({grid[nx][ny], {nx, ny}});
                    vis[nx][ny] = 1;
                }
            }
        }
        return mx;
    }
};