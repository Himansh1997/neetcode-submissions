class Solution {
   public:
    // Recursive Solution with Top Down Approach
    bool solve(int index, string& s, vector<string>& wordDict, vector<int>& dp) {
        if (index >= s.length()) {
            return true;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        for (int l = 1; l <= s.length(); l++) {
            string str = s.substr(index, l);

            for (int i = 0; i < wordDict.size(); i++) {
                if (index + l <= s.length() && wordDict[i] == str) {
                    if (solve(index + l, s, wordDict, dp)) {
                        return dp[index] = true;
                    }
                }
            }
        }
        return dp[index] = false;
    }
    // Bottom Up Approach(Tabulisation)
    bool solveTab(string& s, vector<string>& wordDict) {
        vector<int> dp(s.length() + 1, false);
        dp[s.length()] = true;
        for (int index = s.length() - 1; index >= 0; index--) {
            for (int l = 1; l <= s.length(); l++) {
                string str = s.substr(index, l);

                for (int i = 0; i < wordDict.size(); i++) {
                    if (index + l <= s.length() && wordDict[i] == str) {
                        if (dp[index + l]) {
                            dp[index] = true;
                        }
                    }
                }
            }
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // vector<int> dp(s.length() + 1, -1);
        // return solve(0, s, wordDict, dp);
        return solveTab(s, wordDict);
    }
};
