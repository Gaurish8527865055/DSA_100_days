#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int minVal = nums[0], maxVal = nums[0];
    for (int i = 1; i < numsSize; i++) {
        minVal = MIN(minVal, nums[i]);
        maxVal = MAX(maxVal, nums[i]);
    }

    if (minVal == maxVal) return 0;

    int bucketSize = MAX(1, (maxVal - minVal) / (numsSize - 1));
    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));
    int* bucketUsed = (int*)calloc(bucketCount, sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = 2147483647;
        bucketMax[i] = -2147483648;
    }

    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - minVal) / bucketSize;
        bucketUsed[idx] = 1;
        bucketMin[idx] = MIN(bucketMin[idx], nums[i]);
        bucketMax[idx] = MAX(bucketMax[idx], nums[i]);
    }

    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketCount; i++) {
        if (!bucketUsed[i]) continue;
        maxGap = MAX(maxGap, bucketMin[i] - prevMax);
        prevMax = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);
    free(bucketUsed);

    return maxGap;
}