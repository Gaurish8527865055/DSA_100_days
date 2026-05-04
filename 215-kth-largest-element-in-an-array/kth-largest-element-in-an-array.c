#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Maintains the min-heap property
void minHeapify(int* heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    // 1. Allocate memory for a min-heap of size k
    int* heap = (int*)malloc(k * sizeof(int));
    
    // 2. Initialize heap with first k elements
    for (int i = 0; i < k; i++) {
        heap[i] = nums[i];
    }

    // 3. Build the initial min-heap
    for (int i = k / 2 - 1; i >= 0; i--) {
        minHeapify(heap, k, i);
    }

    // 4. Process remaining elements
    for (int i = k; i < numsSize; i++) {
        if (nums[i] > heap[0]) {
            heap[0] = nums[i]; // Replace root if current element is larger
            minHeapify(heap, k, 0);
        }
    }

    // 5. The root of the min-heap is the kth largest element
    int result = heap[0];
    free(heap);
    return result;
}