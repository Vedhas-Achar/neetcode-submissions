class Solution {
public:
    void dfs(int i, vector<int>& nums, int target, vector<int>& curr, int tot, vector<vector<int>>& res) {
        if (tot == target) {
            res.push_back(curr);
            return;
        }
        if (i >= nums.size() || tot > target) {
            return;
        }

        curr.push_back(nums[i]);
        dfs(i, nums, target, curr, tot + nums[i], res);
        curr.pop_back();
        dfs(i + 1, nums, target, curr, tot, res);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(0, nums, target, curr, 0, res);
        return res;
    }
};