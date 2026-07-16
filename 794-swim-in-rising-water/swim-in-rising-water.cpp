class Solution {
public:
    int n;
    vector<vector<int>> vis;
    vector<vector<vector<int>>> dp;
    vector<vector<int>> grid;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isValid(int x, int y/*, int wl*/) {
        return (
            x>=0 && y>=0 && y<n && x<n && /*grid[x][y] >= wl &&*/ !vis[x][y]
        );
    }
    int rec(int x, int y, int wl) {
        if (x == n-1 && y == n-1) {
            return wl;
        }

        if (dp[x][y][wl] != -1) {
            return dp[x][y][wl];
        }

        int res = INT_MAX;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny)) {
                    vis[nx][ny] = 1;
                    res = min(res, rec(nx, ny, max(wl, grid[nx][ny])));
                    vis[nx][ny] = 0;
            }
        }

        return dp[x][y][wl] = res;
    }

    int swimInWater(vector<vector<int>>& gri) {
        grid = gri;

        n = grid.size();
        vis.assign(n, vector<int>(n, 0));
        dp.assign(n, vector<vector<int>>(n, vector<int>(n*n, -1)));
        vis[0][0] = 1;
        int ans = rec(0, 0, grid[0][0]);
        return ans;
    }
};