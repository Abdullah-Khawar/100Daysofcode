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
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) // If the tree is empty, return true 
            return true;

        queue<TreeNode*> q; // Queue to perform level order traversal
        q.push(root); // Push the root node into the queue

        bool even_level = true; // Flag to track even or odd level
        while (!q.empty()) { // While there are nodes in the queue
            int n = q.size(); // Get the number of nodes at the current level

            int prev = even_level ? INT_MIN : INT_MAX; // Initialize prev value based on even or odd level

            // Process each node at the current level
            for (int i = 0; i < n; ++i) {
                TreeNode* currentValue = q.front(); // Get the front node from the queue
                q.pop(); // Remove the front node from the queue

                // Check conditions for even and odd levels
                if ((even_level && (currentValue->val % 2 == 0 || currentValue->val <= prev)) ||
                    (!even_level && (currentValue->val % 2 != 0 || currentValue->val >= prev)))
                    return false; // If conditions are not met, return false

                prev = currentValue->val; // Update prev value to the current node's value

                // Push the child nodes into the queue if they exist
                if (currentValue->left) q.push(currentValue->left);
                if (currentValue->right) q.push(currentValue->right);
            }
            even_level = !even_level; // Toggle even_level for the next level
        }
        return true; // If all levels satisfy the conditions, return true
    }
};
