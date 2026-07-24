class Solution {
public:
    vector<vector<vector<TreeNode*>>> dp;
    vector<vector<int>> vis;

    vector<TreeNode*> rec(int l, int r) {
        if (l > r) {
            return {nullptr};
        }

        if (vis[l][r]) {
            return dp[l][r];
        }

        vis[l][r] = 1;

        vector<TreeNode*> ans;

        for (int root = l; root <= r; root++) {
            vector<TreeNode*> leftTrees = rec(l, root - 1);
            vector<TreeNode*> rightTrees = rec(root + 1, r);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    ans.push_back(node);
                }
            }
        }

        dp[l][r] = ans;
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        dp.assign(n + 2, vector<vector<TreeNode*>>(n + 2));
        vis.assign(n + 2, vector<int>(n + 2, 0));

        if (n == 0)
            return {};

        return rec(1, n);
    }
};