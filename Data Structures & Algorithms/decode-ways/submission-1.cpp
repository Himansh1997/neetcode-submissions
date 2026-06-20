class Solution {
public:
    // Recursive Solution
    int solve(int i, string& s){
        if(i==s.length()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        int ans= solve(i+1, s);
        if(i+1<s.length()){
            if(s[i]=='1'||(s[i]=='2' && s[i+1] < '7')){
                ans += solve(i+2, s);
            }
        }
        return ans;
    }
    // Top Down Approach (Memoization)
    int solveMem(int i, string& s, vector<int>& dp){
        if(i==s.length()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans= solveMem(i+1, s, dp);
        if(i+1<s.length()){
            if(s[i]=='1'||(s[i]=='2' && s[i+1] < '7')){
                ans += solveMem(i+2, s, dp);
            }
        }
        return dp[i]=ans;
    }
    // Bottom Up Approach (Tabulisation)
    int solveTab(string& s){
        vector<int> dp(s.length()+1, 0);
        dp[s.length()] =1;
        int ans=0;
        for(int i= s.length()-1; i>=0; i--){
            if(s[i]=='0'){
                ans= 0;
            }else{
                 ans= dp[i+1];
            if(i+1<s.length()){
               if(s[i]=='1'||(s[i]=='2' && s[i+1] < '7')){
                  ans += dp[i+2];
            }
        }
         dp[i]=ans;
            }
        }
        return dp[0];
    }
    int numDecodings(string s) {
        vector<int> dp(s.length()+1, -1);
        // return solve(0, s);
        // return solveMem(0, s, dp);
        return solveTab(s);
    }
};
