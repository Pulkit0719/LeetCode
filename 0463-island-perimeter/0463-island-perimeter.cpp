
class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,
            int r, int c) {
        
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds: contributes one perimeter edge
        if (r < 0 || c < 0 || r >= m || c >= n)
            return 1;

        // Water: contributes one perimeter edge
        if (grid[r][c] == 0)
            return 1;

        // Already visited land
        if (visited[r][c])
            return 0;

        visited[r][c] = true;

        // Explore all four directions
        return dfs(grid, visited, r - 1, c) +
               dfs(grid, visited, r + 1, c) +
               dfs(grid, visited, r, c - 1) +
               dfs(grid, visited, r, c + 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Find the first land cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, visited, i, j);
                }
            }
        }

        return 0;
    }
};
