class Solution {
public:
    void dfs(vector<int> adj[], vector<int>& vis, int i){
        vis[i] = 1;
        for(auto x: adj[i]){
            if(!vis[x])
                dfs(adj,vis,x);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V];
        for(int i = 0;i < V;i++){
            for(int j = 0;j < V;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(V,0);
        int count = 0;
        for(int i = 0;i < V;i++){
            if(!vis[i]){
                count++;
                dfs(adj,vis,i);
            }
        }
        return count;
    }
};