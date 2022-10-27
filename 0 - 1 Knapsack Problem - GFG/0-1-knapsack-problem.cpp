// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    int maxProfit(int W, int wt[], int val[], int n, int i)
    {
        if(i == n)
            return 0;
        if(dp[i][W] != -1)
            return dp[i][W];
        int pick = 0;
        if(wt[i] <= W)
         pick = val[i] + maxProfit(W-wt[i], wt, val, n, i+1);
        int notPick = maxProfit(W,wt,val,n,i+1);
        return dp[i][W] = max(pick,notPick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,-1,sizeof dp);
       return maxProfit(W, wt, val, n,0);
       
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends