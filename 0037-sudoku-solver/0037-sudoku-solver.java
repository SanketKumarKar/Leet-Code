class Solution {

    public boolean isValid(int r, int c, char val, char[][] board) {

        // Check row and column
        for (int i = 0; i < 9; i++) {

            if (board[r][i] == val) {
                return false;
            }

            if (board[i][c] == val) {
                return false;
            }
        }

        // Find starting position of 3x3 block
        int blockRow = r - (r % 3);
        int blockCol = c - (c % 3);

        // Check 3x3 block
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                if (board[blockRow + i][blockCol + j] == val) {
                    return false;
                }
            }
        }

        return true;
    }

    public boolean sudoku(int r, int c, char[][] board) {

        // Entire board completed
        if (r == 9) {
            return true;
        }

        // Move to next row
        if (c == 9) {
            return sudoku(r + 1, 0, board);
        }

        // Skip already filled cells
        if (board[r][c] != '.') {
            return sudoku(r, c + 1, board);
        }

        // Try numbers 1 to 9
        for (char num = '1'; num <= '9'; num++) {

            if (isValid(r, c, num, board)) {

                board[r][c] = num;

                if (sudoku(r, c + 1, board)) {
                    return true;
                }

                // Backtrack
                board[r][c] = '.';
            }
        }

        return false;
    }

    public void solveSudoku(char[][] board) {
        sudoku(0, 0, board);
    }
}