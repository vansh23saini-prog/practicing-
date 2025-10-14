#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int n = strlen(s);
    if (numRows == 1 || numRows >= n) {
        char* res = (char*)malloc((n + 1) * sizeof(char));
        strcpy(res, s);
        return res;
    }
    
    // Allocate space for each row
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* lens = (int*)calloc(numRows, sizeof(int));
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((n + 1) * sizeof(char));
        rows[i][0] = '\0'; // Initialize to empty
    }

    int curRow = 0, down = 1;
    for (int i = 0; i < n; i++) {
        int len = lens[curRow];
        rows[curRow][len] = s[i];
        rows[curRow][len + 1] = '\0';
        lens[curRow]++;

        if (curRow == 0) down = 1;
        else if (curRow == numRows - 1) down = 0;
        curRow += down ? 1 : -1;
    }

    // Concatenate all rows into the result
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int pos = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < lens[i]; j++) {
            result[pos++] = rows[i][j];
        }
        free(rows[i]);
    }
    free(rows);
    free(lens);
    result[pos] = '\0';

    return result;
}
