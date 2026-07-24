class Solution {
public:
    bool fun(vector<int>& p, int h, int speed) {
        double time = 0;
        for (int i = 0; i < p.size(); i++) {
            time += (p[i] + speed - 1) / speed;
        }
        if (time <= h)
            return true;
        else
            return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (fun(piles, h, mid)) {
                ans = mid;
                high = mid - 1;    
            } else {
                low = mid + 1;     
            }
        }
        return ans;
    }
};