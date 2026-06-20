class Solution {
public:
    bool valid(int i, vector<int> &board) {
        int n = board.size();
        for (int j = 0; j < n; j++) {
            if (board[j]==i || abs(n-j)==abs(board[j]-i)) return false;
        }
        return true;
    }
    void helper(vector<int> &board, vector<vector<int>> &ans, int &n) {
        if (board.size()==n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (valid(i, board)) {
                board.push_back(i);
                helper(board, ans, n);
                board.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> board;
        vector<vector<int>> temp;

        helper(board, temp, n);
        vector<vector<string>> ans;
        
        for (auto v: temp) {
            vector<string> temp2;
            for (auto s: v) {
                string sample(n, '.');
                sample[s] = 'Q';
                temp2.push_back(sample);
            }
            ans.push_back(temp2);
        }

        return ans;
    }
};