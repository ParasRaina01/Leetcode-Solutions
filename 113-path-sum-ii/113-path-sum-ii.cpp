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
    void dfs(TreeNode* root,int target, vector<vector<int>>& ans,vector<int>& path){
        if(!root)
            return;
        if(!root->left and !root->right){
            if(target - root->val == 0){
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
                return;
            }
            return;
        }
        path.push_back(root->val);
        dfs(root->left,target-root->val,ans,path);
        dfs(root->right,target-root->val,ans,path);
        path.pop_back();
            
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currPath;
        dfs(root,targetSum,ans,currPath);
        return ans;
    }
};