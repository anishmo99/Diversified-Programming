// DFS

class Solution
{
public:
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &seen)
    {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or seen[i][j] or grid[i][j] == 0)
            return 0;

        seen[i][j] = true;

        return (1 + dfs(i + 1, j, grid, seen) + dfs(i, j + 1, grid, seen) + dfs(i - 1, j, grid, seen) + dfs(i, j - 1, grid, seen));
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 and !seen[i][j])
                {
                    ans = max(ans, dfs(i, j, grid, seen));
                }
            }
        }

        return ans;
    }
};

// BFS

class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& grid){
        int count = 1;
        grid[i][j] = 2; // visited
        int dir[5] = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp.first, y = temp.second;
            
            for(int i = 0; i < 4; i++){
                int newx = x + dir[i];
                int newy = y + dir[i + 1];
                
                if(newx >= 0 and newx < grid.size() and newy >= 0 and newy < grid[0].size() and grid[newx][newy] == 1){
                    grid[newx][newy] = 2;
                    count++;
                    q.push({newx, newy});
                }
            }
        }
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1)
                    ans = max(ans, bfs(i, j, grid));
            }
        }
        
        return ans;
    }
};