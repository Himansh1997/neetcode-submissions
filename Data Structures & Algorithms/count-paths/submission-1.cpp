class Solution {
public:
    // Recursion with Top Down Approach(Memoization)
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i==(m-1) || j==(n-1)){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j]=solve(i+1, j, m, n, dp) + solve(i, j+1, m, n, dp);
    }
    //Bottom Up Approach(Tabulisation)
    int solveTab(int m, int n){
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        dp[m-1][n-1]=1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                dp[i][j] +=dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
    //Space Optimisation
    int solveSO(int m, int n){
        vector<int>row(n+1, 0);
        row[n-1]=1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                row[j] =row[j] + row[j+1];
            }
        }
        return row[0];
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m+1,vector<int>(n+1, -1));
        // return solve(0, 0, m, n, dp);
        // return solveTab(m, n);
        return solveSO(m, n);
    }
};
