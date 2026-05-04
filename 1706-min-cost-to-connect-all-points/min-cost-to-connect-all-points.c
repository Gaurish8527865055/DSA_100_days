#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int min_dist[n];
    int visited[n];
    int total_cost = 0;
    int edges_connected = 0;

    for (int i = 0; i < n; i++) {
        min_dist[i] = INT_MAX;
        visited[i] = 0;
    }

    min_dist[0] = 0;

    while (edges_connected < n) {
        int curr_node = -1;
        int curr_min = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && min_dist[i] < curr_min) {
                curr_min = min_dist[i];
                curr_node = i;
            }
        }

        visited[curr_node] = 1;
        total_cost += curr_min;
        edges_connected++;

        for (int next_node = 0; next_node < n; next_node++) {
            if (!visited[next_node]) {
                int dist = abs(points[curr_node][0] - points[next_node][0]) + 
                           abs(points[curr_node][1] - points[next_node][1]);
                
                if (dist < min_dist[next_node]) {
                    min_dist[next_node] = dist;
                }
            }
        }
    }

    return total_cost;
}