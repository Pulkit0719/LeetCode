class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            
            int needed = target - nums[i];
            
            // Check if the required number already exists
            if (mp.find(needed) != mp.end()) {
                return {mp[needed], i};
            }
            
            // Store number and its index
            mp[nums[i]] = i;
        }
        
        return {};
    }
};