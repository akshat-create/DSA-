class Solution {
public:
    void fun(int open, int close, string res, vector<string>& ans, int n) {

        if (open == n && close == n) {
            ans.push_back(res);
            return;
        }

        if (open < n) {
            res.push_back('(');
            fun(open + 1, close, res, ans, n);
            res.pop_back();
        }

        if (close < open) {
            res.push_back(')');
            fun(open, close + 1, res, ans, n);
            res.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res;

        fun(0, 0, res, ans, n);

        return ans;
    }
};