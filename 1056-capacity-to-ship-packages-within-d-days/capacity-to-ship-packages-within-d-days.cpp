class Solution {
public:

    bool fun(vector<int>& wt, int days, int capacity){
        int hold = 0;
        int no_of_days = 1;

        for(int i = 0; i < wt.size(); i++){
            if(hold + wt[i] <= capacity){
                hold += wt[i];
            }
            else{
                no_of_days++;
                hold = wt[i];
            }
        }

        return no_of_days <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low < high){

            int mid = low + (high - low) / 2;

            if(fun(weights, days, mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};