class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(begin(properties),end(properties),comp);
        int cnt = 0;
        int n = properties.size();
        int minDefense = INT_MIN;
        for(int i = 0;i < n;i++){
            if(minDefense > properties[i][1]){
                cnt++;
                continue;
            }
            minDefense = properties[i][1];
        }
        return cnt;
    }
};