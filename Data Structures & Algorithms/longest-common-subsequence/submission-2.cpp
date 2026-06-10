class Solution {
public:
    //Top Down Approach(Recursion+Memoization)
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        if(i >= a.length() || j >= b.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans=0;
        if(a[i] == b[j]){
            ans= 1+ solve(a,b,i+1,j+1,dp);
        }else{
            int op1= solve(a,b,i+1,j,dp);
            int op2= solve(a,b,i,j+1,dp);
            ans= max(op1, op2);
        }
        return dp[i][j]=ans;
    }
    // Bottom Up Approach(Tabulation)
    int solveTab(string& a, string& b){
        vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

        for(int i=a.length()-1; i>=0; i--){
            for(int j=b.length()-1; j>=0; j--){
            int ans=0;
            if(a[i] == b[j]){
                ans= 1+ dp[i+1][j+1];
            }else{
            int op1= dp[i+1][j];
            int op2= dp[i][j+1];
            ans= max(op1, op2);
            }
            dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    //Space Optimization
    int solveSO(string& a, string& b){
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int i=a.length()-1; i>=0; i--){
            for(int j=b.length()-1; j>=0; j--){
            int ans=0;
            if(a[i] == b[j]){
                ans= 1+ next[j+1];
            }else{
            int op1= next[j];
            int op2= curr[j+1];
            ans= max(op1, op2);
            }
            curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        //Top Down Approach(Recursion+Memoization)
        // vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        // return solve(text1,text2,0,0,dp);

        // Bottom Up Approach(Tabulation)
        // return solveTab(text1, text2);

        //Space Optimization
        return solveSO(text1, text2);
    }
};
