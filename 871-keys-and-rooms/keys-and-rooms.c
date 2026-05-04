void dfs(int room, int** rooms, int* roomsColSize, bool* visited) {
    visited[room] = true;
    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(key, rooms, roomsColSize, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    // Allocate memory for visited array and initialize to 0 (false)
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    
    // Start DFS from the first room
    dfs(0, rooms, roomsColSize, visited);
    
    // Check if any room was not visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }
    
    free(visited);
    return true;
}