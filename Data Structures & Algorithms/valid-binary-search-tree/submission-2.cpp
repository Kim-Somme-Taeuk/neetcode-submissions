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
    bool dfs(TreeNode* cur, int min, int max) {
        if (!cur) return true;
        if (cur->val <= min || cur->val >= max) return false;
        return dfs(cur->left, min, cur->val) && dfs(cur->right, cur->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, -1001, 1001);
    }
};
