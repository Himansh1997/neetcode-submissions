class Solution {
public: 
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(0, {}, 0, nums, target);
        return result;
    }
    void dfs(int index, vector<int> current, int total, vector<int>& nums, int target){
        if(total == target){
            result.push_back(current);
            return;
        }
        for(int j= index; j< nums.size(); j++){
            if(total + nums[j] > target){
                return;
            }
            current.push_back(nums[j]);
            dfs(j, current, total + nums[j], nums, target);
            current.pop_back();
        }
    }
};
