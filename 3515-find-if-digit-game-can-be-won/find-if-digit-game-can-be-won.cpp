class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int tot = 0, doublee = 0, single = 0;
        for (auto x: nums){
            tot+=x;{
                if (x < 10){
                    single+= x;
                }
                else{
                    doublee+=x;
                }
            }
        }
        return (2*single > tot || 2*doublee > tot);
    }
};