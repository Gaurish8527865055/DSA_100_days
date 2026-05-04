/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

// 1. Helper function must come BEFORE the main function
int dfs(struct TreeNode* node, int isLeft) {
    if (!node) return 0;
    
    // Check if it's a leaf node
    if (!node->left && !node->right) {
        return isLeft ? node->val : 0;
    }
    
    return dfs(node->left, 1) + dfs(node->right, 0);
}

// 2. The primary function LeetCode calls
int sumOfLeftLeaves(struct TreeNode* root) {
    return dfs(root, 0);
}