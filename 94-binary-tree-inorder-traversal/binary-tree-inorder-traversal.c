/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */
void traverse(struct TreeNode* root, int* arr, int* size) {
    if (!root) return;
    traverse(root->left, arr, size);
    arr[(*size)++] = root->val;
    traverse(root->right, arr, size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    traverse(root, res, returnSize);
    return res;
}