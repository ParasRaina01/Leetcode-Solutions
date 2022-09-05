/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> answer;
        if(!root)
            return answer;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int currentSize = q.size();
            vector<int> currentlevel;
            while(currentSize){
                Node* currNode = q.front();
                q.pop();
                currentlevel.push_back(currNode->val);
                for(Node* &child: currNode->children){
                    if(child)
                        q.push(child);
                }
                currentSize--;
            }
            answer.push_back(currentlevel);
        }
        return answer;
    }
};