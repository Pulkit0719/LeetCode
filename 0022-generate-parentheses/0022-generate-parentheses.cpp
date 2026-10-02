class Solution {
public:
    void backtrack(vector<string>& ans, string current, int open, int close, int n) {
        // Complete valid combination
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add opening bracket
        if (open < n) {
            backtrack(ans, current + '(', open + 1, close, n);
        }

        // Add closing bracket only when valid
        if (close < open) {
            backtrack(ans, current + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        backtrack(ans, "", 0, 0, n);

        return ans;
    }
};