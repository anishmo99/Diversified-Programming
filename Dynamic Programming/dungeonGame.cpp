class Solution {
private:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& arr, int m, int n){
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(m == arr.size() - 1 and n == arr[0].size() - 1)
            return dp[m][n] = min(0, arr[m][n]);
        
        if(m == arr.size() - 1)
            return dp[m][n] = min(0, arr[m][n] + solve(arr, m, n + 1));
        
        if(n == arr[0].size() - 1)
            return dp[m][n] = min(0, arr[m][n] + solve(arr, m + 1, n));
        
        return dp[m][n] = min(0, arr[m][n] + max(solve(arr, m + 1, n), solve(arr, m, n + 1)));
    }
    
public : 
    int calculateMinimumHP(vector<vector<int>>& arr) {
        
        dp.resize(arr.size(), vector<int> (arr[0].size(), -1));
        
        return abs(solve(arr, 0, 0)) + 1;
    }
};