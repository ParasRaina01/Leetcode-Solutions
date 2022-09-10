class Solution {
public:int dp[1001][2][101];
    int maximumProfit(vector<int>& prices, int currday, int canBuy, int transactionCount){
        if(transactionCount == 0)
            return 0;
        if(currday == prices.size())
            return 0; 
        if(dp[currday][canBuy][transactionCount] != -1)
            return dp[currday][canBuy][transactionCount];
        int idle = maximumProfit(prices, currday+1,canBuy,transactionCount);
        if(canBuy == 1){
            int buy = -prices[currday] + maximumProfit(prices, currday+1,0,transactionCount);
            dp[currday][canBuy][transactionCount] = max(buy,idle);
            return max(buy,idle);
        }
        else{
            int sell = prices[currday] + maximumProfit(prices,currday+1,1,transactionCount-1);
            dp[currday][canBuy][transactionCount] = max(idle,sell);
            return max(idle,sell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        memset(dp,-1,sizeof(dp));
        return maximumProfit(prices,0,1,k);
    }
};