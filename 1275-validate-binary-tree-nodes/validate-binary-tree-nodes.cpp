class Solution {
public:

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<int> parent(n, -1);

        for (int i = 0; i < n; i++) {

            int l = leftChild[i];
            int r = rightChild[i];

            if (l != -1) {
                if (parent[l] != -1)
                    return false;

                parent[l] = i;
            }

            if (r != -1) {
                if (parent[r] != -1)
                    return false;

                parent[r] = i;
            }
        }

        int root = -1;

        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {

                if (root != -1)
                    return false;

                root = i;
            }
        }

        if (root == -1)
            return false;

        vector<int> vis(n, 0);
        queue<int> q;

        q.push(root);
        vis[root] = 1;

        int cnt = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            cnt++;

            int l = leftChild[node];
            int r = rightChild[node];

            if (l != -1) {
                if (vis[l])
                    return false;

                vis[l] = 1;
                q.push(l);
            }

            if (r != -1) {
                if (vis[r])
                    return false;

                vis[r] = 1;
                q.push(r);
            }
        }

        return cnt == n;
    }
};