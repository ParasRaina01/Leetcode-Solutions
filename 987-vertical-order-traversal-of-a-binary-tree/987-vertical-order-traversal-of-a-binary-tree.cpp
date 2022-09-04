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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<pair<TreeNode*,pair<int,int>>> nodes;
        nodes.push({root,{0,0}});
        map<int,map<int,multiset<int>>> memo;
        while(!nodes.empty()){
            int currentSize = nodes.size();
            while(currentSize--){
                pair<TreeNode*,pair<int,int>> currPair = nodes.front();
                nodes.pop();
                TreeNode* currNode = currPair.first;
                pair<int,int> intPair = currPair.second;
                int l = intPair.first;
                int h = intPair.second;
                memo[l][h].insert(currNode->val);
                if(currNode->left)
                    nodes.push({currNode->left,{l-1,h+1}});
                if(currNode->right)
                    nodes.push({currNode->right,{l+1,h+1}});
            }
        }
        for(auto el:memo){
            vector<int> col;
            for(auto q: el.second)
                col.insert(col.end(), q.second.begin(), q.second.end());
            ans.emplace_back(col);
        }
        return ans;
    }
};