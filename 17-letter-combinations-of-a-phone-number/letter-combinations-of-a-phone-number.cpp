class Solution {
public:
    void solve(int index, string digits, string temp,vector<string>& res, vector<string>& mapping) {
        // Base Case
        if(index == digits.size()) {
            res.push_back(temp);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        for(char ch : letters) {
            temp.push_back(ch);
            solve(index + 1, digits, temp, res, mapping);
            temp.pop_back();   // Backtracking
        }
    }
    vector<string> letterCombinations(string digits){ 
        vector<string> res;
        if(digits.empty()) return res;
        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        string temp = "";
        solve(0, digits, temp, res, mapping);
        return res;
    }
};