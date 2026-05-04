void traverse(struct TreeNode* root, int* arr, int* size) {
    if (root == NULL) return;

    arr[(*size)++] = root->val;
    traverse(root->left, arr, size);
    traverse(root->right, arr, size);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    traverse(root, result, returnSize);
    return result;
}