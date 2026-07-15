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

    TreeNode* lca(TreeNode* root, int p, int q) {
        if (!root) return NULL;

        if (root->val == p || root->val == q) {
            return root;
        }
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);

        if (left && right) {
            return root;
        }

        return left ? left : right;
    }

    bool getPath(TreeNode* root, int target, string &path) {
        if (!root) {
            return false;
        }

        if (root->val == target) {
            return true;
        }

        path.push_back('L');
        if (getPath(root->left, target, path)) {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (getPath(root->right, target, path)) {
            return true;
        }
        path.pop_back();

        return false;

    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lca(root, startValue, destValue);
        string to_src = "";
        string to_dst = "";

        bool src_check = getPath(LCA, startValue, to_src);
        bool dst_check = getPath(LCA, destValue, to_dst);

        if (src_check && dst_check) {
            string path = "";
            for (int i = 0; i < to_src.size(); i++) {
                path += 'U';
            }
            path += to_dst;
            return path;
        }
        return "";
        
    }
};