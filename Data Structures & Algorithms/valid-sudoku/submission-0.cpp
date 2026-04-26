class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isSudoku = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j])) {
                    for (int x = 0; x < 9; x++) {
                        if (x != i && isdigit(board[x][j])) {
                            if (board[i][j] == board[x][j]) return false;
                        }
                    }
                    for (int y = 0; y < 9; y++) {
                        if (y != j && isdigit(board[i][y])) {
                            if (board[i][j] == board[i][y]) return false;
                        }
                    }
                    for (int x = 0; x < 3; x++) {
                        for (int y = 0; y < 3; y++) {
                            int nx = x + 3 * (i / 3);
                            int ny = y + 3 * (j / 3);
                            if (i != nx && j != ny &&isdigit(board[nx][ny])) {
                                if (board[i][j] == board[nx][ny]) return false;
                            }
                        }
                    }
                }
            }
        }
        return isSudoku;
    }
};
