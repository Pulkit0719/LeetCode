class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            
            int num = nums[i];
            int sum = 0;
            
            // Find sum of digits
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            
            // Check if digit sum equals index
            if (sum == i) {
                return i;
            }
        }
        
        return -1;
    }
};