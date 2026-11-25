class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0], profit = 0;
        for (int p : prices) {
            mn = min(mn, p);
            profit = max(profit, p - mn);
        }
        return profit;
    }
};