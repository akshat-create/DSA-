class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        double maxavg = sum;
        for(int i = 0, j = k; j < n; i++, j++){
            sum = sum - nums[i] + nums[j];  
            maxavg = max(maxavg, sum);
        }

        return maxavg / k;
    }
};