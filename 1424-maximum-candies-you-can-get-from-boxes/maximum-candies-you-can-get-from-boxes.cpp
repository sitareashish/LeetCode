class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        int n = status.size();
        vector<int> boxFound(n, 0);
        vector<int> vis(n, 0);
        for (int x : initialBoxes) {
            q.push(x);
            boxFound[x] = 1;
        }

        int ans = 0;
        while (!q.empty())  {
            int i = q.front();
            q.pop();

            if (vis[i]) {
                continue;
            }

            for (int i = 0; i < n; i++) {
                if (!vis[i]) continue;
                if (boxFound[i]) {
                    q.push(i);
                }
            }
            if (status[i]) {
                ans+= candies[i];
                for (int x : keys[i]) {
                    status[x] = 1;
                    if (boxFound[x]==1 && !vis[x]) {
                        q.push(x);
                    }
                }
                for (int x : containedBoxes[i]) {
                    boxFound[x] = 1;
                    q.push(x);
                }
            }
            else {
                continue;
            }
            
            vis[i] = 1; 
        }
        return ans;
    }
};