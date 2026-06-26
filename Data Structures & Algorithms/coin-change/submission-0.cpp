class Solution {
   public:
    // Recursive Solution with Top Down Approach(Memoization)
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return INT_MAX;
        }
        if (dp[amount] != -1) {
            return dp[amount];
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int ans = solve(coins, amount - coins[i], dp);
            if (ans != INT_MAX) {
                mini = min(mini, 1 + ans);
            }
        }
        return dp[amount] = mini;
    }
    // Bottom Up Approach(Tabulisation)
    int solveTab(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int target = 1; target <= amount; target++) {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
                if (target - coins[i] >= 0) {
                    int ans = dp[target - coins[i]];
                    if (ans != INT_MAX) {
                        mini = min(mini, 1 + ans);
                    }
                }
                dp[target] = mini;
            }
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount + 1, -1);
        int ans = solveTab(coins, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
