#include <limits.h>
#include <ctype.h>

int myAtoi(char * s){
    // Step 1: Ignore leading whitespace
    while (*s == ' ') s++;

    // Step 2: Check for sign
    int sign = 1;
    if (*s == '+' || *s == '-') {
        if (*s == '-') sign = -1;
        s++;
    }

    // Step 3: Read digits and ignore leading zeros
    long result = 0; // Use long for overflow check but not 64-bit type strictly
    while (*s >= '0' && *s <= '9') {
        int digit = *s - '0';
        // Check overflow/underflow conditions before multiplying by 10
        if (result > (LONG_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        result = result * 10 + digit;
        s++;
    }

    result *= sign;

    // Step 4: Clamp result if overflowed 32-bit int range
    if (result > INT_MAX) return INT_MAX;
    if (result < INT_MIN) return INT_MIN;

    return (int)result;
}
