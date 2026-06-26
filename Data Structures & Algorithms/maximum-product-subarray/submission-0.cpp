class Solution {
public:
    int solve(int i, vector<int>& nums, int prefix, int suffix, int ans){
        if(i >= nums.size()){
            return ans;
        }
        if(prefix==0){
            prefix=1;
        }
        if(suffix==0){
            suffix=1;
        }
        prefix= prefix*nums[i];
        suffix= suffix*nums[nums.size()-i-1];
        ans= max(ans, max(prefix, suffix));
        return solve(i+1, nums, prefix, suffix, ans);
    }
    int maxProduct(vector<int>& nums) {
        return solve(0, nums, 1, 1, INT_MIN);
    }
};
