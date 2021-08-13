#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int h, w;
    int newBoard[25][25] = {-1};
    
    int x[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int y[8] = {1, 0, -1, 1, -1, -1, 0, 1};
    
    bool canVisit(int i, int j) {
        return i >= 0 and j >=0 and i < h and j < w;
    }
    
    int countNeighbors(vector<vector<int>>& board, int i, int j) {
        int n = 0;
        for (int k = 0; k < 8; k++)
            if (canVisit(i+x[k], j+y[k]) and board[i+x[k]][j+y[k]])
                n++;

        return n;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        h = board.size();
        w = board[0].size();
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int n = countNeighbors(board, i, j);
                
                if (n > 3 or n < 2) // overpopulation or under-population
                    newBoard[i][j] = 0;
                
                else if (n == 3) // reproduction or stable
                    newBoard[i][j] = 1;
                
                else
                    newBoard[i][j] = board[i][j]; // stable
            }
        }
        
        // updating board
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                board[i][j] = newBoard[i][j];
    }
};