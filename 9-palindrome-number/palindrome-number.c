#include <stdbool.h>

bool isPalindrome(int x) {
    // Negative numbers and multiples of 10 (except 0) are not palindrome
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    // When the length is odd, we can get rid of the middle digit by revertedNumber/10
    return (x == revertedNumber || x == revertedNumber / 10);
}
