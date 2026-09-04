class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check karo column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check karo upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check karo upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string>& board, int row, int n) {

        // saari queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // iss row ke saare column try karo
        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                // Place queen
                board[row][col] = 'Q';

                // Move to next row
                solve(board, row + 1, n);

                // Backtrack karo and place "."
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(board, 0, n);

        return ans;
    }
};