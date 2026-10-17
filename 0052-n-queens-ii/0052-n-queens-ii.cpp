
class Solution {
public:
    int count = 0;

    void solve(int row, int n, vector<bool>& cols,
               vector<bool>& diag1, vector<bool>& diag2) {
        
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col + n - 1;
            int d2 = row + col;

            if (cols[col] || diag1[d1] || diag2[d2])
                continue;

            // Place queen
            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            solve(row + 1, n, cols, diag1, diag2);

            // Backtrack
            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        solve(0, n, cols, diag1, diag2);

        return count;
    }
};
