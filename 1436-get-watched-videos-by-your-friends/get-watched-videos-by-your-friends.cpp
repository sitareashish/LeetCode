class Solution {
public:
    int n;
    int L;
    vector<vector<int>> graph;
    vector<int> vis;
    queue<int> q;

    void bfs(int node) {
        q.push(node);
        vis[node] = 1;

        int lvl = 0;

        while (!q.empty() && lvl < L) {
            int sz = q.size();

            while (sz--) {
                int val = q.front();
                q.pop();

                for (int x : graph[val]) {
                    if (vis[x])
                        continue;

                    vis[x] = 1;
                    q.push(x);
                }
            }

            lvl++;
        }
    }

    vector<string> watchedVideosByFriends(
        vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends,
        int id,
        int level
    ) {
        n = friends.size();
        L = level;
        graph = friends;

        vis.assign(n, 0);

        bfs(id);

        map<string, int> mp;

        while (!q.empty()) {
            int val = q.front();
            q.pop();

            for (string ch : watchedVideos[val]) {
                mp[ch]++;
            }
        }

        vector<string> ans;

        for (auto& p : mp)
            ans.push_back(p.first);

        sort(ans.begin(), ans.end(), [&](string& a, string& b) {
            if (mp[a] == mp[b])
                return a < b;
            return mp[a] < mp[b];
        });

        return ans;
    }
};