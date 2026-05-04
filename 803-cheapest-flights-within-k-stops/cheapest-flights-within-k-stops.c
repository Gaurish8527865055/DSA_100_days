#include <limits.h>
#include <string.h>

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    long dist[n];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i <= k; i++) {
        long temp[n];
        memcpy(temp, dist, sizeof(dist));
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];
            if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }
        memcpy(dist, temp, sizeof(dist));
    }

    return dist[dst] == INT_MAX ? -1 : (int)dist[dst];
}