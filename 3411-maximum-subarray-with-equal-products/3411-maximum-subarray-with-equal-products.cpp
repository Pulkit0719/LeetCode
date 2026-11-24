
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Maximum possible GCD * LCM when nums[i] <= 10
        const long long LIMIT = 25200;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0, l = 1;

            for (int j = i; j < n; j++) {
                // Prevent integer overflow
                if (prod > LIMIT / nums[j])
                    break;

                prod *= nums[j];

                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);

                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
