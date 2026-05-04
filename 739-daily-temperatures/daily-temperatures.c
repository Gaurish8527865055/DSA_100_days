#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    int* answer = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top--];
            answer[prevIndex] = i - prevIndex;
        }
        stack[++top] = i;
    }

    free(stack);
    return answer;
}