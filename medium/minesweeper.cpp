#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int h, w;
    vector<int> temp;
    char map[9] = {'B','1','2','3','4','5','6','7','8'};
    int x[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int y[8] = {1, 0, -1, 1, -1, -1, 0, 1};
    
    bool canVisit(int x, int y) {
        return (x >= 0 and x < h and y >= 0 and y < w);
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0], c = click[1];
        
        h = board.size();
        w = board[0].size();

        // mine clicked
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        
        // empty square clicked
        if (board[r][c] == 'E') {
            
            short int mines = 0;
            
            for (int i = 0; i < 8; i++) { // count adjacent mines
                if (canVisit(r+x[i], c+y[i]) and board[r+x[i]][c+y[i]] == 'M')
                    mines++;
            }
            
            board[r][c] = map[mines]; // change clicked block
            
            for (int i = 0; i < 8; i++) { // look at adjacent blocks
                temp.clear();
                temp.push_back(r+x[i]);
                temp.push_back(c+y[i]);
                
                if (canVisit(r+x[i], c+y[i]) and  // not beyond the edges
                    board[r][c] == 'B' and  // current block is empty, doesn't have adj mines
                    board[temp[0]][temp[1]] == 'E' // adj block has empty
                   ) 
                    board = updateBoard(board, temp); // reveal adj empty squares
            }
            return board;
        }
        
        return board;
    }
};