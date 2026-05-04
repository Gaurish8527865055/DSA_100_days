int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = 0, high = 0;
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > low) low = weights[i];
        high += weights[i];
    }

    while (low < high) {
        int mid = low + (high - low) / 2;
        int current_weight = 0;
        int days_needed = 1;

        for (int i = 0; i < weightsSize; i++) {
            if (current_weight + weights[i] > mid) {
                days_needed++;
                current_weight = 0;
            }
            current_weight += weights[i];
        }

        if (days_needed > days) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}