#include <stdbool.h>

bool canEatAll(int* piles, int pilesSize, int h, int k) {
    long long hoursSpent = 0;
    for (int i = 0; i < pilesSize; i++) {
        hoursSpent += (piles[i] + k - 1) / k;
    }
    return hoursSpent <= h;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1;
    int high = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > high) high = piles[i];
    }

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canEatAll(piles, pilesSize, h, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}