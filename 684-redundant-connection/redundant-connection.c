#include <stdlib.h>

int find(int* parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unite(int* parent, int* rank, int rootX, int rootY) {
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int n = edgesSize;
    int* parent = (int*)malloc((n + 1) * sizeof(int));
    int* rank = (int*)calloc((n + 1), sizeof(int));
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        int rootU = find(parent, u);
        int rootV = find(parent, v);
        
        if (rootU == rootV) {
            result[0] = u;
            result[1] = v;
        } else {
            unite(parent, rank, rootU, rootV);
        }
    }

    free(parent);
    free(rank);
    return result;
}