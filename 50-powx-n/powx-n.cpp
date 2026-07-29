class Solution {
public:
    double fun(double x, long long n) {

        if (n == 0)
            return 1;

        if (n % 2 == 0)
            return fun(x * x, n / 2);
        return x * fun(x, n - 1);
    }
    double myPow(double x, int n) {
        long long pwr = n;
        if (pwr < 0) {
            x = 1 / x;
            pwr = -pwr;
        }
        return fun(x, pwr);
    }
};