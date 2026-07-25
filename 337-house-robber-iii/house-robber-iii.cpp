/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<pair<TreeNode*, int>, int> dp;

    int rec(TreeNode* root, int canRob) {
        if (root == NULL) {
            return 0;
        }

        if (dp.count({root, canRob})) {
            return dp[{root, canRob}];
        }

        int res;

        if (!canRob) {
            res = rec(root->left, 1) + rec(root->right, 1);
        } else {
            int rob = root->val + rec(root->left, 0) + rec(root->right, 0);
            int skip = rec(root->left, 1) + rec(root->right, 1);
            res = max(rob, skip);
        }

        return dp[{root, canRob}] = res;
    }

    int rob(TreeNode* root) {
        return rec(root, 1);
    }
};