class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<int>& nums, vector<int>& mul,int idx,int start)
    {
        if(idx==mul.size())
            return 0;
        if(dp[start][idx]!=INT_MIN)
            return dp[start][idx];
        int left=rec(nums,mul,idx+1,start+1)+nums[start]*mul[idx];
        int right=rec(nums,mul,idx+1,start)+nums[nums.size()-1-(idx-start)]*mul[idx];
        return dp[start][idx]=max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));    
        return rec(nums,multipliers,0,0);
    }
};