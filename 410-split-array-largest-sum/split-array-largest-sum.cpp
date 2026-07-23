class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int limit) {
        int count = 1;int sum = 0;
        for (int x : nums) {
            if (sum + x <= limit) {
                sum += x;
            } else {
                count++;
                sum = x;
            }
        }  return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } return ans;
    }
};