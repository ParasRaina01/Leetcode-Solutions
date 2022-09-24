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
    int ans = 0;
    void dfs(TreeNode* root,int direction, int currLen){
        if(!root)
            return ;
        ans = max(ans,currLen);
        if(direction){
            dfs(root->left, not direction, currLen+1);
            dfs(root->right, direction, 1);
        }
        else{
            dfs(root->right, not direction, currLen+1);
            dfs(root->left, direction,1);
        }
        
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,0,0);
        return ans;
    }
};