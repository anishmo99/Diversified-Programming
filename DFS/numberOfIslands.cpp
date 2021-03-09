class Solution
{
public:
    bool isValid(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] == '1' && !visited[i][j];
    }

    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;
        vector<pair<int, int>> offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int k = 0; k < offsets.size(); ++k)
        {
            int next_i = i + offsets[k].first;
            int next_j = j + offsets[k].second;
            if (isValid(next_i, next_j, grid, visited))
            {
                dfs(next_i, next_j, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int islands(0);
        if (grid.size() == 0)
        {
            return islands;
        }

        if (grid[0].size() == 0)
        {
            return islands;
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(i, j, grid, visited);
                    ++islands;
                }
            }
        }

        return islands;
    }
};