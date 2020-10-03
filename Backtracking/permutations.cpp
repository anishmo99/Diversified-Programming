// USING SWAP WITH DFS (optimal backtracking)

class Solution
{
    vector<vector<int>> result;

public:
    void dfs(vector<int> &nums, int start)
    {
        if (start == nums.size() - 1)
        {
            result.emplace_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {

        dfs(nums, 0);

        return result;
    }
};