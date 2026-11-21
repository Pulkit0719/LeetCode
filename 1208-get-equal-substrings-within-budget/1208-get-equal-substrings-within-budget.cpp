
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int left = 0;
        int totalCost = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            totalCost += abs(s[right] - t[right]);

            while (totalCost > maxCost) {
                totalCost -= abs(s[left] - t[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

