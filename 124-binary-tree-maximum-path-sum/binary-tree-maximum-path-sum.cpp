/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans;

    int dfs(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        // Maximum path passing through the current node
        ans = max(ans, left + right + node->val);

        // Return the maximum gain to the parent
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};