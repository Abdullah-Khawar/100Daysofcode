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
    // Function to check if two binary trees are identical
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both trees are empty, they are identical
        if(p == NULL && q == NULL) return true;
        // If one tree is empty while the other is not, they are not identical
        if(p == NULL || q == NULL) return false;
        
        // Create queues to perform level order traversal of both trees
        queue <TreeNode*> q1;
        queue <TreeNode*> q2;

        // Push the roots of both trees into their respective queues
        q1.push(p);
        q2.push(q);

        // Perform level order traversal simultaneously on both trees
        while(!q1.empty() && !q2.empty()){
            // Get the front nodes of both queues
            TreeNode* node1 = q1.front(); q1.pop();
            TreeNode* node2 = q2.front(); q2.pop();

            // If the values of the nodes are not equal, the trees are not identical
            if(node1->val != node2-> val) return false;

            // If both nodes have left children, push them into their respective queues
            if(node1->left != NULL && node2->left != NULL){
                q1.push(node1->left);
                q2.push(node2->left);
            } 
            // If only one of the nodes has a left child, the trees are not identical
            else if(node1->left != NULL || node2->left != NULL) return false;

            // If both nodes have right children, push them into their respective queues
            if(node1->right != NULL && node2->right != NULL){
                q1.push(node1->right);
                q2.push(node2->right);
            } 
            // If only one of the nodes has a right child, the trees are not identical
            else if(node1->right != NULL || node2->right != NULL) return false;
        }

        // If the traversal completes without finding any differences, the trees are identical
        return true;
    }
};
