#include <stdbool.h>
#include <string.h>

bool dp[21][21];      // DP memo table
bool visited[21][21]; // To avoid recomputation

bool dfs(const char* s, int i, const char* p, int j) {
    if (visited[i][j]) return dp[i][j];
    visited[i][j] = true;
    
    if (p[j] == '\0') {
        dp[i][j] = (s[i] == '\0');
        return dp[i][j];
    }
    
    bool first_match = (s[i] != '\0' && (p[j] == s[i] || p[j] == '.'));
    
    if (p[j+1] == '*') {
        // Match zero occurrence of p[j] OR at least one occurrence if first_match is true
        dp[i][j] = (dfs(s, i, p, j + 2) || (first_match && dfs(s, i + 1, p, j)));
    } else {
        dp[i][j] = first_match && dfs(s, i + 1, p, j + 1);
    }
    return dp[i][j];
}

bool isMatch(char * s, char * p){
    memset(visited, 0, sizeof(visited));
    return dfs(s, 0, p, 0);
}
