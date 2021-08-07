class Solution {
    bool isValidRow(vector<vector<char>>& board, int row) {
        bool exists[10] = {false};
        for (auto i : board[row]) {
            if (i == '.') // skip empty positions
                continue;
            int val = i - '0';
            if (exists[val])
                return false;
            exists[val] = true;
        }
        return true;
    }
    
    bool isValidCol(vector<vector<char>>& board, int col) {
        bool exists[10] = {false};
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == '.') // skip empty positions
                continue;
            int val = board[i][col] - '0';
            if (exists[val])
                return false;
            exists[val] = true;
        }
        return true;
    }
    
    bool isValidBox(vector<vector<char>>& board, int x, int y) {
        bool exists[10] = {false};
        for (int i = x; i < x+3; i++) {
            for (int j = y; j < y+3; j++) {
                if (board[i][j] == '.') // skip empty positions
                    continue;
                int val = board[i][j] - '0';
                if (exists[val])
                    return false;
                exists[val] = true;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid = true;
        
        // check rows and columns
        for (int i = 0; i < 9; i++) {
            if(!isValidRow(board, i)) return false;
            if(!isValidCol(board, i)) return false;
        }
        
        // check boxes
        for (int i = 0; i < 9; i+=3)
            for (int j = 0; j < 9; j+=3)
                if (!isValidBox(board, i, j))
                    return false;
        
        return true;
    }
};