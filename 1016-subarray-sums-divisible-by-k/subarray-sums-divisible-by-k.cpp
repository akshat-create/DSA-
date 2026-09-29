class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int x : nums) {
            sum += x;
            int r = sum % k;
            if(r < 0)
                r += k;
            ans += mp[r];
            mp[r]++;
        }
        return ans;
    }
};