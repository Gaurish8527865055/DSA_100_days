typedef struct {
    int r, c, time;
} Orange;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int fresh_count = 0;
    
    // Create a queue large enough for all cells
    Orange queue[rows * cols];
    int head = 0, tail = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 2) {
                queue[tail++] = (Orange){r, c, 0};
            } else if (grid[r][c] == 1) {
                fresh_count++;
            }
        }
    }

    if (fresh_count == 0) return 0;

    int max_time = 0;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (head < tail) {
        Orange curr = queue[head++];
        max_time = curr.time;

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dirs[i][0];
            int nc = curr.c + dirs[i][1];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                grid[nr][nc] = 2;
                fresh_count--;
                queue[tail++] = (Orange){nr, nc, curr.time + 1};
            }
        }
    }

    return (fresh_count == 0) ? max_time : -1;
}