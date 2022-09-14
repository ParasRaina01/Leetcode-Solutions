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
    int count = 0;
    
    void dfs(TreeNode* root, vector<int> res)
    {
        if(!root)
            return;
        res[root -> val]++;
        if(root -> left == NULL && root -> right == NULL)
        {
            int odd_count = 0;
            
            for(auto x : res){
                if(x % 2)
                    odd_count++;
            }
            if(odd_count <= 1)
                count++;
            return;
        }       
        dfs(root -> left, res);
        
        dfs(root -> right, res);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> res(10,0);
        dfs(root,res);
        return count;
    }
};