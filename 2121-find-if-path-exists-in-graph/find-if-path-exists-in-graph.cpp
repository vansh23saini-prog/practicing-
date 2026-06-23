class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        vector<vector<int>> g(n);
        for (auto& e : edges) { g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }
        vector<bool> vis(n, false);
        auto dfs = [&](auto& self, int u) -> bool {
            if (u == dst) return true;
            vis[u] = true;
            for (int v : g[u]) if (!vis[v] && self(self, v)) return true;
            return false;
        };
        return dfs(dfs, src);
    }
};
