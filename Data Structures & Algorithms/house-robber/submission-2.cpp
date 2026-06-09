class Solution{
    public:
    int solve(vector<int>& nums, int index, vector<int>& dp){
        int n= nums.size();
        if(index < 0){
            return 0;
        }
        if(index == 0){
            return nums[0];
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int include= nums[index] + solve(nums, index-2, dp);
        int exclude= solve(nums, index-1, dp);
        return max(include, exclude);
    }
    int solveTab(vector<int>& nums){
        int n= nums.size();
        vector<int> dp(n, 0);
        dp[0]= nums[0];
        for(int i=1; i<n; i++){
            if(i-2 >= 0){
              int include= nums[i] + dp[i-2];
              int exclude= dp[i-1];
              dp[i]= max(include, exclude);
            }
        }
        return dp[n-1];
    }
    int solveSO(vector<int>& nums){
        int n= nums.size();
        int prev2=0;
        int prev1= nums[0];

        for(int i=1; i<n; i++){
            int include= nums[i] + prev2;
            int exclude= prev1;
            int ans= max(include, exclude);
            prev2= prev1;
            prev1= ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums){
        // int n= nums.size();
        // vector<int> dp(n+1, -1);
        // return solve(nums, n-1, dp);
        // return solveTab(nums);
        return solveSO(nums);
    }
};