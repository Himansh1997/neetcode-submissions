class Solution{
    public:
    // Top-Down Approach(Recusrion+Memoization)
    int solve(int n, vector<int>& dp){
        if(n <= 2){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans= solve(n-1, dp)+ solve(n-2, dp);
        return dp[n]=ans;
    }
    // Bottom-Up Approach(Tabulation)
    int solveTab(int n){
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3; i<=n; i++){
            int ans= dp[i-1] + dp[i-2];
            dp[i]= ans;
        }
        return dp[n];
    }
    // Space Optimization
    int solveSO(int n){
        int prev1=1;
        int prev2=1;
        for(int i=0; i<n-1; i++){
            int ans= prev1+prev2;
            prev2= prev1;
            prev1= ans;
        }
        return prev1;
    }
    int climbStairs(int n){
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);
        // return solveTab(n);
        return solveSO(n);
    }
};