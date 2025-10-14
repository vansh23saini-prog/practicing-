#include <string.h>

/**
 * @brief Finds the length of the longest substring without repeating characters.
 * @param s The input string.
 * @return The length of the longest substring.
 */
int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if (n == 0) {
        return 0;
    }

    // `last` stores the last seen index of each character.
    // Initialized to -1 to indicate characters not seen yet.
    int last[256];
    for (int i = 0; i < 256; i++) {
        last[i] = -1;
    }

    int maxLen = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        unsigned char c = s[end];

        // If the character was seen before and is within the current window,
        // move the start pointer to the right of its last occurrence.
        if (last[c] >= start) {
            start = last[c] + 1;
        }

        // Update the last seen index for the current character.
        last[c] = end;

        // Calculate the length of the current window and update maxLen if needed.
        int currentLen = end - start + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}
