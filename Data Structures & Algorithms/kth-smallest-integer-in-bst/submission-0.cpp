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
    int count = 0;
    int answer = 0;
    void inorder (TreeNode* cur, int target) {
        if (!cur) return;

        inorder(cur->left, target);

        count++;
        if (count == target) {
            answer = cur->val;
            return;
            }

        inorder(cur->right, target);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return answer;
    }
};
