class Solution {
public:
    int dominantIndex(vector<int>& nums) {

        int n = nums.size();
        int maxx = INT_MIN;
        int index = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > maxx) {
                maxx = nums[i];
                index = i;
            }
        }
        for (int i = 0; i < n; ++i) {

            if (maxx == nums[i])
                continue;

            if (maxx < 2 * nums[i])
                return -1;
        }

        return index;
    }
};