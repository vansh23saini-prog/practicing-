/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize) {
    *returnSize = 0;
    if (digits[0] == '\0') return NULL;

    const char *mapping[] = {
        "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    int len = strlen(digits);
    // Max combinations (4^len)
    int maxComb = 1;
    for (int i = 0; i < len; i++) {
        if (digits[i] == '7' || digits[i] == '9')
            maxComb *= 4;
        else
            maxComb *= 3;
    }

    char **result = (char **)malloc(maxComb * sizeof(char *));
    char *combination = (char *)malloc(len + 1);
    combination[len] = '\0';

    void backtrack(int pos) {
        if (pos == len) {
            result[*returnSize] = strdup(combination);
            (*returnSize)++;
            return;
        }
        const char *letters = mapping[digits[pos] - '2'];
        for (int i = 0; letters[i] != '\0'; i++) {
            combination[pos] = letters[i];
            backtrack(pos + 1);
        }
    }

    backtrack(0);
    free(combination);
    return result;
}
