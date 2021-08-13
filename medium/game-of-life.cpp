#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int h, w;
    
    int x[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int y[8] = {1, 0, -1, 1, -1, -1, 0, 1};
    
    bool canVisit(int i, int j) {
        return i >= 0 and j >=0 and i < h and j < w;
    }
    
    int countNeighbours(vector<vector<int>>& board, int i, int j) {
        int n = 0;
        for (int k = 0; k < 8; k++) {
            if (canVisit(i+x[k], j+y[k]) and board[i+x[k]][j+y[k]])
                n++;
        }
        return n;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        h = board.size();
        w = board[0].size();
        
        vector<vector<int>> newBoard;
        vector<int> temp;
        
        for (int i = 0; i < w; i++)
            temp.push_back(-1);

        for (int i = 0; i < h; i++)
            newBoard.push_back(temp);
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int n = countNeighbours(board, i, j);
                
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