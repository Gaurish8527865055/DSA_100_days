#include <stdbool.h>
#include <stdlib.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++) {
        color[i] = 0; 
    }

    int* queue = (int*)malloc(graphSize * sizeof(int));

    for (int i = 0; i < graphSize; i++) {
        if (color[i] != 0) continue;

        int head = 0, tail = 0;
        queue[tail++] = i;
        color[i] = 1; 

        while (head < tail) {
            int u = queue[head++];
            for (int j = 0; j < graphColSize[u]; j++) {
                int v = graph[u][j];
                if (color[v] == 0) {
                    color[v] = -color[u];
                    queue[tail++] = v;
                } else if (color[v] == color[u]) {
                    free(color);
                    free(queue);
                    return false;
                }
            }
        }
    }

    free(color);
    free(queue);
    return true;
}