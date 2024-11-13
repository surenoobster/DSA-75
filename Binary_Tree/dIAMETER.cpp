class Solution {
public:
    int maxDiameter = 0;

    // Helper function to calculate the height of the tree
    int height(TreeNode* node) {
        if (!node) {
            return 0;
        }

        // Calculate the height of left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Update the maximum diameter
        maxDiameter = std::max(maxDiameter, leftHeight + rightHeight);

        // Return the height of the current node
        return 1 + std::max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root); // Compute the height, which also updates maxDiameter
        return maxDiameter; // Return the maximum diameter found
    }
};