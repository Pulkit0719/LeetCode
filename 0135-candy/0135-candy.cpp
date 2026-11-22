
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> candies(n, 1);

        // Pass 1: Compare with left neighbor
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Pass 2: Compare with right neighbor
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i],
                                 candies[i + 1] + 1);
            }
        }

        // Calculate minimum total candies
        int total = 0;

        for (int c : candies) {
            total += c;
        }

        return total;
    }
};
