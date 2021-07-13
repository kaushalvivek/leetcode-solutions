#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool checkCapture(int i, int j, int m, int n, vector<vector<char>>& board, vector<vector<char>>& visited) {
        
        if (i == m-1 or j == n-1 or i == 0 or j == 0) return false; // return false for edges
        
        visited[i][j] = '1'; // mark current 'O' as visited
        
        static int x[] = {1, -1, 0, 0};
        static int y[] = {0, 0, 1, -1};

        for (int p = 0; p < 4; p++) 
        {        
            if (board[i+x[p]][j+y[p]] == 'O') // for adjacent Os
            {   
                if (visited[i+x[p]][j+y[p]] == '1') // if visited, skip revisit
                    continue;
                
                if (visited[i+x[p]][j+y[p]] == '2') // if abandoned, end search
                    return false;
                
                if (!checkCapture(i+x[p], j+y[p], m, n, board, visited))
                    return false;
            }       
        }
        
        return true;
    }
    
    void capture(int i, int j, int m, int n, vector<vector<char>>& board) {
        
        board[i][j] = 'X'; // capture 
        
        static int x[] = {1, -1, 0, 0};
        static int y[] = {0, 0, 1, -1};
        
        for (int p = 0; p < 4; p++) {
            if (board[i+x[p]][j+y[p]] == 'O') {
                capture(i+x[p], j+y[p], m, n, board);
            }
        }
        return;
    }
    
    void abandon(int i, int j, int m, int n, vector<vector<char>>& board, vector<vector<char>>& visited) {
        
        visited[i][j] = '2'; // abandon
        
        static int x[] = {1, -1, 0, 0};
        static int y[] = {0, 0, 1, -1};
        
        for (int p = 0; p < 4; p++) {
            int curr_x = i+x[p];
            int curr_y = j+y[p];
            
            // skip areas outside map
            if  (curr_x < 0 or curr_y < 0 or curr_x > m-1 or curr_y > n-1) continue;
            
            if (board[curr_x][curr_y] == 'O' and visited[curr_x][curr_y] != '2') {
                abandon(curr_x, curr_y, m, n, board, visited);
            }
        }
        return;
    }
    
    
    void solve(vector<vector<char>>& board) {
        int m,n;
        m = board.size();
        n = board[0].size();
        
        vector<vector<char>> visited;
        vector<char> temp;
        for(int i = 0; i < n; i++) {
            temp.push_back('0');
        }
        for(int i = 0; i < m; i++) {
            visited.push_back(temp);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (board[i][j] == 'O' and visited[i][j] == '0') // for unvisited O
                {
                    bool canCapture = checkCapture(i, j, m, n, board, visited);
                    
                    if (canCapture) capture(i, j, m, n, board);
                    else abandon(i, j, m, n, board, visited);
                }
            }
        }
        
        return;
    }
};