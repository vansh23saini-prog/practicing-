int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        // Check for overflow before multiplying
        if (rev > 214748364 || (rev == 214748364 && pop > 7)) return 0;   // INT_MAX = 2147483647
        if (rev < -214748364 || (rev == -214748364 && pop < -8)) return 0; // INT_MIN = -2147483648
        rev = rev * 10 + pop;
    }
    return rev;
}
