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
    int result = 0;

    void solve(TreeNode* root, vector<int>& cnt) {
        if (root == NULL) return;

        cnt[root->val]++; // Increment the count for the current node's value

        // Check if the current node is a leaf node
        if (root->left == NULL && root->right == NULL) {
            int oddFreq = 0;
          
            // Count the number of values with odd frequency in the path
            for (int i = 1; i <= 9; i++) {
                if (cnt[i] % 2 != 0) {
                    oddFreq++;
                }
            }

            // If at most one value has odd frequency, the path is
            // pseudo-palindromic
            if (oddFreq <= 1) {
                result++;
            }
        }

        // Recursively traverse the left and right subtrees
        solve(root->left, cnt);
        solve(root->right, cnt);

        cnt[root->val]--; // Decrement the count after backtracking
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> cnt(10, 0); // Initialize an array to count the frequency of each digit
        solve(root, cnt);
        return result; // Return the final count of pseudo-palindromic paths
    }
};
