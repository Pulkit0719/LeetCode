class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    void solve(int index, vector<int>& nums) {
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }
        // Include nums[index]
        current.push_back(nums[index]);
        solve(index + 1, nums);
        current.pop_back();
        solve(index + 1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};