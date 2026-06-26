class Solution {
public:
    // Recursive and Top Down Approach(Memoization)
    int solve(int i, vector<int>& nums, int prefix, int suffix, int ans, vector<int>& dp){
        if(i >= nums.size()){
            return ans;
        }
        if(prefix==0){
            prefix=1;
        }
        if(suffix==0){
            suffix=1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int maxi= INT_MIN;
        prefix= prefix*nums[i];
        suffix= suffix*nums[nums.size()-i-1];
        ans= max(ans, max(prefix,suffix));
        maxi= solve(i+1, nums, prefix, suffix, ans, dp);
        return dp[i]=maxi;
    }
    int maxProduct(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(0, nums, 1, 1, INT_MIN, dp);
    }
};
