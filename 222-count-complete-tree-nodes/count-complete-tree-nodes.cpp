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
    int countNodes(TreeNode* root, int l = -1, int r = -1) {
        if (!root) return 0;
        if (l < 0) for (auto t = root; t; t = t->left) l++;
        if (r < 0) for (auto t = root; t; t = t->right) r++;
        return l == r ? (1 << (l + 1)) - 1 : 1 + countNodes(root->left, l - 1, -1) + countNodes(root->right, -1, r - 1);
    }
};
