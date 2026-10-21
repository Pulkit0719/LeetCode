class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,
             int color, int originalColor) {

        int m = image.size();
        int n = image[0].size();

        // Check boundaries and original color
        if (sr < 0 || sc < 0 || sr >= m || sc >= n ||
            image[sr][sc] != originalColor) {
            return;
        }

        // Fill the current pixel
        image[sr][sc] = color;

        // Visit all four adjacent pixels
        dfs(image, sr + 1, sc, color, originalColor);
        dfs(image, sr - 1, sc, color, originalColor);
        dfs(image, sr, sc + 1, color, originalColor);
        dfs(image, sr, sc - 1, color, originalColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int originalColor = image[sr][sc];

        // Avoid infinite recursion if colors are identical
        if (originalColor == color) {
            return image;
        }

        dfs(image, sr, sc, color, originalColor);

        return image;
    }
};