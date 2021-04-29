// accepted leetcode

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j])
                {
                    if (dict.find(s.substr(j, i - j)) != dict.end())
                    {
                        // cout << (s.substr(j, i - j)) << " ";
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

// MCM

class Solution {
public:
    vector<string> dict;
    vector<vector<int>> dp;
    
    bool solve(string& s, int i, int j){
        if(i > j)
            return dp[i][j] = false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        for(string& x : dict)
            if(s.substr(i, j - i + 1) == x)
                return dp[i][j] = true;
        
        for(int k = i; k <= j - 1; k++){
            if(solve(s, i, k) and solve(s, k + 1, j))
                return dp[i][j] = true;
        }
        
        return dp[i][j] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        dict = wordDict;
        int n = s.size();
        dp.clear();
        dp.resize(n + 1, vector<int> (n + 1, -1));
        return solve(s, 0, n - 1);
    }
};