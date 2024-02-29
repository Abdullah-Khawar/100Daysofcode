class Solution {
public:
    int solve(TreeNode* root, int &result){
        if (root == nullptr)
            return 0;

        int left = solve(root->left, result);
        int right = solve(root->right, result);

        result = max(result, left + right); 

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int result = INT_MIN;

        solve(root, result);
        return result;
    }
};
