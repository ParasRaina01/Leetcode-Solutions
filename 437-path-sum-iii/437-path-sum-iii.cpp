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
	unordered_map<long,int> mp;
	void dfs(TreeNode* root,long sum,int& targetSum) {
		if(!root) 
            return;
		sum += root->val;
		ans += mp[sum-targetSum];
		mp[sum]++;
		dfs(root->left,sum,targetSum);
		dfs(root->right,sum,targetSum);
		mp[sum]--;
	}
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        dfs(root,0,targetSum);
        return ans;
    }
};