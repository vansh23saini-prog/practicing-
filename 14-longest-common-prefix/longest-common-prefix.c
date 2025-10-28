char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    static char prefix[201];
    int index = 0;

    while (1) {
        char c = strs[0][index];
        if (c == '\0') break;
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][index] != c || strs[i][index] == '\0') {
                prefix[index] = '\0';
                return prefix;
            }
        }
        prefix[index] = c;
        index++;
    }
    prefix[index] = '\0';
    return prefix;
}
