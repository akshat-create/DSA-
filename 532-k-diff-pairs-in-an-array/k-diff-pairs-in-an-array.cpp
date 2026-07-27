class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x : nums)
            mp[x]++;
        int ans = 0;
        if(k == 0)
        {
            for(auto it : mp)
            {
                if(it.second > 1)
                    ans++;
            }
        }    
        else {
            for(auto it : mp)
            {
               if(mp.count(it.first + k))
                ans++;
            }
        } return ans;
    }
};