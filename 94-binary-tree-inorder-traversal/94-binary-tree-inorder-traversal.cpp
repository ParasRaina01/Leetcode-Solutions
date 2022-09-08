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
    void dfs(TreeNode* root, vector<int>& nodes){
        if(!root)
            return;
        dfs(root->left,nodes);
        nodes.emplace_back(root->val);
        dfs(root->right,nodes);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
};