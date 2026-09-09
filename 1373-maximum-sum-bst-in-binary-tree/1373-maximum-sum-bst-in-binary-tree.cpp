class Solution {
    struct Info {
        int minValue;
        int maxValue;
        int sum;
        bool isBST;
    };
    int maxSum = 0;
    Info dfs(TreeNode* root) {
        if (!root) {
            return {INT_MAX, INT_MIN, 0, true};
        }

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        if (!left.isBST || !right.isBST ||
            root->val <= left.maxValue ||
            root->val >= right.minValue) {
            return {0, 0, 0, false};
        }

        int sum = left.sum + root->val + right.sum;

        maxSum = max(maxSum, sum);

        return {
            min(left.minValue, root->val),
            max(right.maxValue, root->val),
            sum,
            true
        };
    }

public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};