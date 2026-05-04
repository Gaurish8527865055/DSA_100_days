#include <stdbool.h>

bool canSplit(int* nums, int numsSize, int k, long long maxSum) {
    int count = 1;
    long long currentSum = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (currentSum + nums[i] > maxSum) {
            count++;
            currentSum = nums[i];
            if (count > k) return false;
        } else {
            currentSum += nums[i];
        }
    }
    return true;
}

int splitArray(int* nums, int numsSize, int k) {
    long long low = 0;
    long long high = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low) low = nums[i];
        high += nums[i];
    }
    
    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canSplit(nums, numsSize, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return (int)result;
}