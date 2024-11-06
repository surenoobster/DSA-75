class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
private:
    void helper(TreeNode* root) {
        if (root == nullptr) return;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Swap the left and right children
        swap(root->left, root->right); 

        helper(root->left);
        helper(root->right);
    }
};