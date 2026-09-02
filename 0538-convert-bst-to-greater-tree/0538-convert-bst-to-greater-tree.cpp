class Solution {
public:
    int sum = 0;

    void reverseInorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        // Visit larger values first
        reverseInorder(root->right);

        // Add current value to sum
        sum += root->val;
        root->val = sum;

        // Visit smaller values
        reverseInorder(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};