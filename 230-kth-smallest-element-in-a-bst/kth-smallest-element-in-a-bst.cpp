class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // Go as far left as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Visit the node
            curr = st.top();
            st.pop();

            k--;

            // If this is the kth smallest
            if (k == 0) {
                return curr->val;
            }

            // Move to right subtree
            curr = curr->right;
        }

        return -1;
    }
};