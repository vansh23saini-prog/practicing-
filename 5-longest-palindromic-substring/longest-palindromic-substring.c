#include <string.h>

// Helper function to expand around the center and return palindrome length
int expandAroundCenter(char* s, int left, int right) {
    int n = strlen(s);
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    // Note: Subtract 1 from both sides because loop goes one step further when it breaks
    return right - left - 1;
}

// Main solution function for LeetCode
char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n < 1) return "";

    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        int len1 = expandAroundCenter(s, i, i);     // Odd length
        int len2 = expandAroundCenter(s, i, i + 1); // Even length
        int len = (len1 > len2) ? len1 : len2;
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    // +2 for null terminator and inclusivity
    int maxLen = end - start + 1;
    char* result = (char*)malloc(sizeof(char) * (maxLen + 1));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
}
