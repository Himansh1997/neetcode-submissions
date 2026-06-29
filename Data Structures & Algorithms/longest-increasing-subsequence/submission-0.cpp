class Solution {
   public:
    int solve(int n, vector<int>& nums, int currIndex, int prevIndex, vector<vector<int>>& dp) {
        if (currIndex >= n) {
            return 0;
        }
        if (dp[currIndex][prevIndex + 1] != -1) {
            return dp[currIndex][prevIndex];
        }
        int include = 0;
        if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            include = 1 + solve(n, nums, currIndex + 1, currIndex, dp);
        }
        int exclude = solve(n, nums, currIndex + 1, prevIndex, dp);
        return dp[currIndex][prevIndex + 1] = max(include, exclude);
    }
    int solveTab(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                int include = 0;
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
                    include = 1 + dp[currIndex + 1][currIndex+1];
                }
                int exclude = dp[currIndex + 1][prevIndex+1];
                dp[currIndex][prevIndex + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int solveSO(vector<int>& nums) {
        int n = nums.size();
        vector<int>next(n+1, 0);
        vector<int>curr(n+1, 0);
        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                int include = 0;
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
                    include = 1 + next[currIndex+1];
                }
                int exclude = next[prevIndex+1];
                curr[prevIndex + 1] = max(include, exclude);
            }
            next=curr;
        }
        return next[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solve(n, nums, 0, -1, dp);
        // return solveTab(nums);
        return solveSO(nums);
    }
};
