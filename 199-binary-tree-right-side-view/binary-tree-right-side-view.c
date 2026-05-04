/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */

int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;

    int* result = (int*)malloc(100 * sizeof(int));
    struct TreeNode** queue = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    
    int head = 0, tail = 0;
    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            
            if (i == levelSize - 1) {
                result[(*returnSize)++] = node->val;
            }
            
            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
    }

    free(queue);
    return result;
}