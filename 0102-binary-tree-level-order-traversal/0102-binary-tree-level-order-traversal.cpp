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
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>>res;
      if(!root) return res;
      queue<TreeNode *> q;
      q.push(root);
      while(!q.empty()){
        int cnt = q.size();
        vector<int>v;
        while(cnt){
            TreeNode* curr = q.front();
            q.pop();
            v.push_back(curr -> val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            --cnt;
            }
            res.push_back(v);
      }
      return res;
    }
};