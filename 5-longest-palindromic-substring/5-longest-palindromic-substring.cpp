class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> memo(n,vector<int>(n,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j <= i;j++){
                if(s[i] == s[j]){
                    if(i > 0 and j < n-1 and memo[i-1][j+1])
                        memo[i][j] = 1;
                    
                    if(i-1 <= j+1)
                        memo[i][j] = 1;
                }
                
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(memo[i][j])
                    ans = max(ans,i-j+1);
            }
        }
        string res;
        for(int i = 0;i < n;i++){
            int f=0;
            for(int j = 0;j < n;j++){
                if(memo[j][i] && ans == j-i+1){
                    res = s.substr(i,j-i+1);
                    f=1;
                    break ;
                }
            }
            if(f)break;
        }
        return res;
    }
};