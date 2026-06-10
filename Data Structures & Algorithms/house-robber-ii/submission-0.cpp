class Solution {
public:
    int solve(vector<int>& nums, int start, int end, vector<int>& dp){
        if(start > end){
            return 0;
        }
        if(dp[start] != -1){
            return dp[start];
        }
        int include= nums[start] + solve(nums, start+2, end, dp);
        int exclude= solve(nums, start+1, end, dp);
        return dp[start]= max(include, exclude);
    }
    // Bottom Up Approach
    int solveTab(vector<int>& nums, int start, int end){
        int n= end-start+1;
        vector<int> dp(n+2, 0);
        for(int i= n-1; i>=0; i--){
            int include= nums[start+i] + dp[i+2];
            int exclude= dp[i+1];
            dp[i]= max(include, exclude);
        }
        return dp[0];
    }
    int solveSO(vector<int>& nums, int start, int end){
        int prev1=0;
        int prev2=0;

        for(int i= start; i<=end; i++){
            int include= nums[i] + prev2;
            int exclude= prev1;
            int ans= max(include, exclude);
            prev2= prev1;
            prev1= ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
       int n= nums.size();
       if(n == 1){
        return nums[0];
       }

       // For Top Down Approach
    //    vector<int> dp1(n+1, -1);
    //    vector<int> dp2(n+1, -1);

    //    int case1= solve(nums, 0, n-2, dp1);
    //    int case2= solve(nums, 1, n-1, dp2);
       
       //For Bottom Up Approach
    //    int case1= solveTab(nums, 0, n-2);
    //    int case2= solveTab(nums, 1, n-1);

       // For Space Optimization
       int case1= solveSO(nums, 0, n-2);
       int case2= solveSO(nums, 1, n-1);
       return max(case1, case2);
    }
};
