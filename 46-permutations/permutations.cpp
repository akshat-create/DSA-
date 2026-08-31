class Solution {
public:

    void perms(vector<int>& nums, vector<int>& freq,
               vector<int>& temp, vector<vector<int>>& res) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (freq[i] == 1)
                continue;
            freq[i] = 1;
            temp.push_back(nums[i]);

            perms(nums, freq, temp, res);

            temp.pop_back();
            freq[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> freq(nums.size(), 0);
        perms(nums, freq, temp, res);
        return res;
    }
};