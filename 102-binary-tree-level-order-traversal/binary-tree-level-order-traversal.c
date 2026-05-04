int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    int** result = malloc(2000 * sizeof(int*));
    *returnColumnSizes = malloc(2000 * sizeof(int));
    struct TreeNode** queue = malloc(2000 * sizeof(struct TreeNode*));
    
    int head = 0, tail = 0;
    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;
        (*returnColumnSizes)[*returnSize] = levelSize;
        result[*returnSize] = malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            result[*returnSize][i] = node->val;
            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
        (*returnSize)++;
    }

    free(queue);
    return result;
}