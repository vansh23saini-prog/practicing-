class Solution {
public:
    int divide(int dividend, int divisor) {
        long long INT_MAXI = 2147483647;
        long long INT_MINI = -2147483648;

        // overflow case
        if (dividend == INT_MINI && divisor == -1) {
            return INT_MAXI;
        }

        // sign check
        bool negative = (dividend < 0) != (divisor < 0);

        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long ans = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while (a >= (temp << 1)) {
                temp = temp << 1;
                multiple = multiple << 1;
            }

            a = a - temp;
            ans = ans + multiple;
        }

        if (negative) ans = -ans;

        return (int)ans;
    }
};