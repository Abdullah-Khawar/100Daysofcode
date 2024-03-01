/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // Initialize a queue to perform level-order traversal
        queue<TreeNode*> q;

        // Declare a variable to store the value of the bottom-left node
        int bottomLeft;

        // Add the root node to the queue
        q.push(root);

        // Perform level-order traversal
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int n = q.size();

            // Iterate through all nodes at the current level
            while (n--) {
                // Get the front node from the queue
                TreeNode* node = q.front();
                q.pop();

                // Update the bottomLeft value with the value of the current node
                bottomLeft = node->val;

                // Add the right child of the current node to the queue if it exists
                if (node->right)
                    q.push(node->right);

                // Add the left child of the current node to the queue if it exists
                if (node->left)
                    q.push(node->left);
            }
        }

        // Return the value of the bottom-left node
        return bottomLeft;
    }
};
