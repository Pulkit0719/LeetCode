class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;

    long long dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= m || c < 0 || c >= n ||
            grid[r][c] == 0 || visited[r][c]) {
            return 0;
        }

        visited[r][c] = true;

        long long sum = grid[r][c];

        sum += dfs(r + 1, c, grid);
        sum += dfs(r - 1, c, grid);
        sum += dfs(r, c + 1, grid);
        sum += dfs(r, c - 1, grid);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        visited.assign(m, vector<bool>(n, false));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    long long sum = dfs(i, j, grid);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};