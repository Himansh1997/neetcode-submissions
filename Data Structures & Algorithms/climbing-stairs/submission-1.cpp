class Solution {
public:
    int solve (int n, int index, vector<int>& dp){
        if(index == n){
            return 1;
        }
        if(index > n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int ans= solve(n, index+1, dp) + solve(n, index+2, dp);
        return dp[index]= ans;
    }
    int climbStairs(int n) {
        vector<int> dp(n, -1);
       return solve(n, 0, dp);
    }
};
