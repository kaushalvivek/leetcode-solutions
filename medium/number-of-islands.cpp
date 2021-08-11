#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int islands = 0;
    int h, w;
    const int x[4] = {1, -1, 0, 0};
    const int y[4] = {0, 0, 1, -1};
    
    bool isSafe(int i, int j) {
        return (i < h and i >= 0 and j < w and j >= 0);
    }
    
    void DFS (
        vector<vector<bool>>& visited,
        vector<vector<char>>& grid,
        int i,
        int j,
        bool freshCall
    ) {
        
        if (visited[i][j])
            return;
            
        
        visited[i][j] = true;
        
        // its water
        if (grid[i][j] == '0')
            return;
        
        // its land
            
        // new island
        if (freshCall)
            islands++;
        
        // check nieghbours
        for (int k = 0; k < 4; k++) {
            if (isSafe(i+x[k], j+y[k]))
                DFS(visited, grid, i+x[k], j+y[k], false);
        }
        
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        if (grid.size() == 0)
            return 0;
        
        vector<vector<bool>> visited;
        h = grid.size();
        w = grid[0].size();
        
        vector<bool> temp;
        
        for (int i = 0; i < w; i++) {
            temp.push_back(false);
        }
        
        for (int i = 0; i < h; i++) {
            visited.push_back(temp);
        }
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                DFS(visited, grid, i, j, true);
            }
        }
        return islands;
    }
};