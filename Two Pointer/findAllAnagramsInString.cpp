class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> maps;
        unordered_map<char, int> mapp;
        
        for(int i = 0; i < p.size(); i++)
            mapp[p[i]]++;
        
        
        vector<int> ans;
        int kp = p.size();
        int ks = 0;
        int i = 0, j = 0;
        
        while(j < s.length()){
            if(ks < kp){
                ks++;
                maps[s[j]]++;
                j++;
            }
            
            if(ks == kp and maps != mapp){
                maps[s[i]]--;
                if(maps[s[i]] == 0)
                    maps.erase(s[i]);
                ks--;
                i++;
            }
            
            else if(maps == mapp){
                ans.push_back(i);
                maps[s[i]]--;
                if(maps[s[i]] == 0)
                    maps.erase(s[i]);
                ks--;
                i++;
            }
            
        }
        
        return ans;
    }
};