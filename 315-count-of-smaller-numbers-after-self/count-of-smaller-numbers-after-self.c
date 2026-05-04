#include <stdlib.h>

void merge(int* nums, int* indices, int* counts, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* left_indices = (int*)malloc(n1 * sizeof(int));
    int* right_indices = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) left_indices[i] = indices[left + i];
    for (int j = 0; j < n2; j++) right_indices[j] = indices[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int right_count = 0;

    while (i < n1 && j < n2) {
        if (nums[right_indices[j]] < nums[left_indices[i]]) {
            right_count++;
            indices[k++] = right_indices[j++];
        } else {
            counts[left_indices[i]] += right_count;
            indices[k++] = left_indices[i++];
        }
    }

    while (i < n1) {
        counts[left_indices[i]] += right_count;
        indices[k++] = left_indices[i++];
    }
    while (j < n2) {
        indices[k++] = right_indices[j++];
    }

    free(left_indices);
    free(right_indices);
}

void mergeSort(int* nums, int* indices, int* counts, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(nums, indices, counts, left, mid);
        mergeSort(nums, indices, counts, mid + 1, right);
        merge(nums, indices, counts, left, mid, right);
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* counts = (int*)calloc(numsSize, sizeof(int));
    int* indices = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        indices[i] = i;
    }

    mergeSort(nums, indices, counts, 0, numsSize - 1);

    free(indices);
    return counts;
}