/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
        if(!root) return 0;
        int lp = maxDepth(root -> left);
        int rp = maxDepth(root -> right);
        return 1 + fmax(lp,rp);
    
}