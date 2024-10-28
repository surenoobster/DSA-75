# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def height_measure(self, node):
        if not node:
            return 0
        
        left_height = self.height_measure(node.left)
        if left_height == -1:
            return -1
        
        right_height = self.height_measure(node.right)
        if right_height == -1:
            return -1
        
        if abs(left_height - right_height) > 1:
            return -1
        
        return 1 + max(left_height, right_height)

    def isBalanced(self, root):
        return self.height_measure(root) != -1



        /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int heightmeasure(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = heightmeasure(node->left);
        if (leftHeight == -1) return -1;
        
        int rightHeight = heightmeasure(node->right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return 1 + max(leftHeight, rightHeight); 
    }

public:
    bool isBalanced(TreeNode* root) {
        return heightmeasure(root) != -1;
    }
};