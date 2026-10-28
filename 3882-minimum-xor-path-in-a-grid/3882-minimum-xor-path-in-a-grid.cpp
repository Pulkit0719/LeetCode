class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int X = 1024;

        vector<vector<bool>> prev(n, vector<bool>(X, false));
        vector<vector<bool>> curr(n, vector<bool>(X, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fill(curr[j].begin(), curr[j].end(), false);

                if (i == 0 && j == 0) {
                    curr[j][grid[i][j]] = true;
                    continue;
                }

                for (int x = 0; x < X; x++) {
                    if (i > 0 && prev[j][x]) {
                        curr[j][x ^ grid[i][j]] = true;
                    }

                    if (j > 0 && curr[j - 1][x]) {
                        curr[j][x ^ grid[i][j]] = true;
                    }
                }
            }

            swap(prev, curr);
        }

        for (int x = 0; x < X; x++) {
            if (prev[n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};