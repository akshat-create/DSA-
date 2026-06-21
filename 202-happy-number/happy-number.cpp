class Solution {
public:
    int fun(int num) {
        int sum = 0;
        while (num > 0) {
            int d = num % 10;
            num = num / 10;
            sum += d * d;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;

        do {
            slow = fun(slow);           // 1 step
            fast = fun(fun(fast));      // 2 steps
        } while (slow != fast);

        return slow == 1;
    }
};