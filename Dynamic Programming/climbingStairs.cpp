class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};

// OR

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        
        int first = 1, second = 2;
        for(int i = 2; i < n; i++){
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};

class Solution {
public:
    vector<int> dp;
    
    int solve(int& A, int pos)
    {   
        if(pos == 0)
            return 1;
        
        if(pos < 0)
            return 0;
        
        if(dp[pos] != -1)
            return dp[pos];
        
        return dp[pos] = solve(A, pos - 1) + solve(A, pos - 2);
    }
    
    int climbStairs(int A) {
    
        dp.clear();
        dp.resize(A+1,-1);
        
        return solve(A, A);
    }
};

