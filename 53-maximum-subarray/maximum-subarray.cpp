class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int bestend = nums[0];
        int ans = nums[0];

        for ( i=1;i<n;i++){
            int v1 = nums[i];
            int v2 = nums[i] + bestend;
            bestend= max(v1,v2);
            ans=max(ans,bestend);
        }
        return ans;

        
    }
};