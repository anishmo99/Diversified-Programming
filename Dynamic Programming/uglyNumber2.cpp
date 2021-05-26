class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n);
        
        int n2 = 2, n3 = 3, n5 = 5;
        int i2 = 0, i3 = 0, i5 = 0;
        
        v[0] = 1;
        int next = 1;
        
        for(int i = 1; i < n; i++){
            next = min(n2, min(n3, n5));
            v[i] = next;
            
            if(v[i] == n2)
                n2 = 2 * v[++i2];
            
            if(v[i] == n3)
                n3 = 3 * v[++i3];
            
            if(v[i] == n5)
                n5 = 5 * v[++i5];
        }
        
        return v[n - 1];
    }
};