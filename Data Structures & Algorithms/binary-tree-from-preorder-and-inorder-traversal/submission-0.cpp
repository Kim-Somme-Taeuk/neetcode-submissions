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
    int preIndex = 0;
    unordered_map<int, int> inIndex;

    TreeNode* dfs(vector<int>& preorder, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;

        int rootVal = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(rootVal);

        int mid = inIndex[rootVal];

        root->left = dfs(preorder, inLeft, mid - 1);
        root->right = dfs(preorder, mid + 1, inRight);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inIndex[inorder[i]] = i;
        }

        return dfs(preorder, 0, preorder.size() - 1);
    }
};
