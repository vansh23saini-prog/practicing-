class Solution {
    int count = 0;

public:
    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));

        place(board, 0);

        return count;
    }

private:
    void place(vector<vector<char>>& board, int row) {
        if (row == board.size()) {
            count++;
            return;
        }

        for (int col = 0; col < board.size(); col++) {
            if (safe(board, row, col)) {
                board[row][col] = 'Q';

                place(board, row + 1);

     
                board[row][col] = '.';
            }
        }
    }

    bool safe(vector<vector<char>>& board, int row, int col) {

        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

       
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0;
             i--, j--) {

            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1;
             i >= 0 && j < board.size();
             i--, j++) {

            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};